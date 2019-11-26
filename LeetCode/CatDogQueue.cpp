/*
* 实现一个猫狗队列
*/

#include <iostream>
#include <string>
#include <queue>
#include <memory>

using namespace std;

class Pet {
public:
	Pet(const string &type)
		: m_type(type)
	{ }

	string GetType() const
	{
		return m_type;
	}
	virtual void Speak() const = 0;
private:
	string m_type;
};

class Cat : public Pet {
public:
	Cat() : Pet("cat")
	{ }
	void Speak() const
	{
		cout << "miao miao miao!" << endl;
	}
};

class Dog : public Pet {
public:
	Dog() : Pet("dog")
	{ }
	void Speak() const
	{
		cout << "wang wang wang!" << endl;
	}
};

class PetEntry {
public:
	PetEntry() = default;
	PetEntry(Pet *p_pet, size_t idx)
		: m_sp_pet(p_pet), m_index(idx)
	{ }

	size_t GetIndex() const
	{
		return m_index;
	}
	shared_ptr<Pet> GetPetSptr() const
	{
		return m_sp_pet;
	}

private:
	shared_ptr<Pet> m_sp_pet;
	size_t m_index;
};

class CatDogQueue {
public:
	void Push(Pet *p_pet);
	shared_ptr<Pet> PopAll();
	shared_ptr<Pet> PopCat();
	shared_ptr<Pet> PopDog();

	bool Empty() const
	{
		return m_cat_queue.empty() && m_dog_queue.empty();	
	}
	bool CatEmpty() const
	{
		return m_cat_queue.empty();
	}
	bool DogEmpty() const
	{
		return m_dog_queue.empty();
	}

private:
	queue<PetEntry> m_cat_queue;
	queue<PetEntry> m_dog_queue;
	size_t m_count = 0;
};

void CatDogQueue::Push(Pet *p_pet)
{
	if (p_pet->GetType() == "cat") {
		m_cat_queue.push(PetEntry(p_pet, m_count++));
	} else if (p_pet->GetType() == "dog") {
		m_dog_queue.push(PetEntry(p_pet, m_count++));
	} else {
		cout << "Error pet type." << endl;
	}
}

shared_ptr<Pet> CatDogQueue::PopAll()
{
	if (Empty()) {
		cout << "PopAll empty queue." << endl;
		return nullptr;
	}
	PetEntry entry;
	if (!CatEmpty() && !DogEmpty()) {
		if (m_cat_queue.front().GetIndex() < m_dog_queue.front().GetIndex()) {
			entry = m_dog_queue.front();
			m_dog_queue.pop();
		} else {
			entry = m_cat_queue.front();
			m_cat_queue.pop();
		}
	} else if (!CatEmpty()) {
		entry = m_cat_queue.front();
		m_cat_queue.pop();
	} else {
		entry = m_dog_queue.front();
		m_dog_queue.pop();
	}
	return entry.GetPetSptr();
}

shared_ptr<Pet> CatDogQueue::PopCat()
{
	if (CatEmpty()) {
		cout << "Cat queue is empty." << endl;
		return nullptr;
	}
	PetEntry entry = m_cat_queue.front();
	m_cat_queue.pop();
	return entry.GetPetSptr();
}

shared_ptr<Pet> CatDogQueue::PopDog()
{
	if (DogEmpty()) {
		cout << "Dog queue is empty." << endl;
		return nullptr;
	}
	PetEntry entry = m_dog_queue.front();
	m_dog_queue.pop();
	return entry.GetPetSptr();
}

int main()
{
	CatDogQueue my_cdq;
	my_cdq.PopAll();
	my_cdq.PopCat();
	my_cdq.PopDog();

	my_cdq.Push(new Cat());
	shared_ptr<Pet> ptr = my_cdq.PopAll();
	if (ptr) {
		ptr->Speak();
		cout << "type is: " << ptr->GetType() << endl;
	}
	ptr = my_cdq.PopCat();
	if (!ptr) {
		cout << "000" << endl;
	}
	ptr = my_cdq.PopDog();
	if (!ptr) {
		cout << "111" << endl;
	}

	my_cdq.Push(new Dog());
	my_cdq.Push(new Dog());
	my_cdq.Push(new Dog());
	ptr = my_cdq.PopCat();
	if (!ptr) {
		cout << "222" << endl;
	}
	ptr = my_cdq.PopDog();
	if (ptr) {
		ptr->Speak();
		cout << "type is: " << ptr->GetType() << endl;
	}

	return 0;
}