#include <iostream>
#include <string>
using namespace std;
typedef struct animal
{
	string name;
	string species;
	int age;
};
void add_animal(animal animal_array[], int& last_place_in_array, int base);
void delete_animal(animal animal_array[], int& last_place_in_array);
void find(animal animal_array[], int last_place_in_array);
void notInBase();
void modify(animal animal_array[], int last_place_in_array);
void show(animal animal_array[], int last_place_in_array);
void ageIsANumber();


int main()
{
	setlocale(LC_ALL, "pl_PL");

	int last_place_in_array = 0;
	int base;
	cout << "How big base do you want? : ";
	cin >> base;

	animal* animal_array = new animal[base];

	int value = 6;

	do
	{
		cout << "\tMENU" << endl
			<< "Decide what you wanna do? (give number):" << endl
			<< "1- add an animal to base." << endl
			<< "2- delete an animal from base." << endl
			<< "3- find an animal in base." << endl
			<< "4- modify existing animal." << endl
			<< "5- show the base." << endl
			<< "6- close the program." << endl
			<< "choice: ";
		cin >> value;

		if (value == 1)
		{
			add_animal(animal_array, last_place_in_array, base);
			
		}
		else if (value == 2)
		{
			delete_animal(animal_array, last_place_in_array);
		}
		else if (value == 3)
		{
			find(animal_array, last_place_in_array);
		}
		else if (value == 4)
		{
			modify(animal_array, last_place_in_array);
		}
		else if (value == 5)
		{
			show(animal_array, last_place_in_array);
		}
	} 	while (value != 6);
	system("pause");
	return 0;
}
void add_animal(animal animal_array[], int& last_place_in_array, int base)
{
	int n;
	cout << "How many animals you want to register?: ";
	cin >> n;


	for (int i = last_place_in_array; i < last_place_in_array + n; i++)
	{
		if (i != base)
		{
			cout << "Animal: " << endl;
			cout << "Enter the species: ";
			cin >> animal_array[i].species;
			cout << "Enter the name: ";
			cin >> animal_array[i].name;
			cout << "Enter the age : ";
			cin >> animal_array[i].age;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				cout << "Enter the age : ";
				std::cin >> animal_array[i].age;
			}
			
			
		}
		else
		{
			cout << "The base can't hold so many animals." << endl;
		}

	}
	last_place_in_array += n;
}

void delete_animal(animal animal_array[], int& last_place_in_array)
{
	cout << "Data of the animal, that you want to remove:" << endl;;
	int age;
	string species, name;
	cout << "Enter the species: ";
	cin >> species;
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the age: ";
	cin >> age;
	for (int i = 0; i < last_place_in_array; i++)
	{
		if (animal_array[i].species == species && animal_array[i].name == name && animal_array[i].age == age)
		{

			for (int j = i + 1; j < last_place_in_array - 1; i++)
			{
				animal_array[j].species = animal_array[i].species;
				animal_array[j].name = animal_array[i].name;
				animal_array[j].age = animal_array[i].age;
			}

			cout << "An animal was removed from base." << endl;
			break;
		}

	}
	last_place_in_array -= 1;

}
void find(animal animal_array[], int last_place_in_array)
{
	cout << "Data of the animal, that you want to find:" << endl;;
	int age;
	string species, name;
	cout << "Enter the species: ";
	cin >> species;
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the age: ";
	cin >> age;
	for (int i = 0; i < last_place_in_array; i++)
	{
		if (animal_array[i].species == species && animal_array[i].name == name && animal_array[i].age == age)
		{

			cout << "Your animal is at " << i << "place in base. "
				<< "Animal : " << animal_array[i].species << " , " << animal_array[i].name << endl;


		}
		else
		{
			notInBase();
		}
	}
}
void modify(animal animal_array[], int last_place_in_array)
{
	cout << "Data of the animal, that you want to modify:" << endl;;
	int age, value;
	string species, name;
	cout << "Enter the species: ";
	cin >> species;
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the age: ";
	cin >> age;
	cout << "What do you want to modify ? " << endl
		<< "1-species" << endl
		<< "2-name" << endl
		<< "3-age" << endl;
	cin >> value;
	for (int i = 0; i < last_place_in_array; i++)
	{
		if (animal_array[i].species == species && animal_array[i].name == name && animal_array[i].age == age)
		{

			if (value == 1)
			{
				cout << "Enter the new species for an animal : " << endl;
				cin >> animal_array[i].species;
			}
			else if (value == 2)
			{
				cout << "Enter the new name for an animal : " << endl;
				cin >> animal_array[i].name;
			}
			else if (value == 3)
			{
				cout << "Enter the new age for animal :" << endl;
				cin >> animal_array[i].age;
			}

		}
		else
		{
			notInBase();
		}
	}
}
void show(animal animal_array[], int last_place_in_array)
{
	if (last_place_in_array != 0) {
		for (int i = 0; i < last_place_in_array; i++)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << i << " place: ";
			cout << " SPECIES: " << animal_array[i].species << " NAME: " << animal_array[i].name << " AGE: " << animal_array[i].age << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "EMPTY BASE" << endl;
	}
}
void notInBase()
{

	cout << "THERE IS NO SUCH ANIMAL." << endl;

}
void ageIsANumber()
{
	cout << "You have entered not a number for age, try again." << endl;
}
