#include <iostream>
#include <string>

using namespace std;

class Drug
{
private:
	string name;
	double cost;
	bool recipe;
	string country;
	int releaseform;

public:

	// конструкторы и деструктор
	Drug();
	Drug(string name, double cost, bool recipe, string country, int releaseform);
	Drug(const Drug& other);
	~Drug();

	//ввывод
	void print_name();
	void print_cost();
	void print_recipe();
	void print_country();
	void print_releaseform();

	//редактирование полей
	void redact_name(const string& newname);
	void redact_cost(const double& newcost);
	void redact_recipe();
	void redact_country(const string& newcountry);
	void redact_releaseform(const int& newreleaseform);

	//функции
	static void maxcost(const Drug drugs[], int size, const string& country);
	static void ratiorecipe(const Drug drugs[], int size, const string& country);
	static void listdrugs(const Drug drugs[], int size, const int form);
};


Drug::Drug() :
	name(""), cost(0.0), recipe(false), country(""), releaseform(1) {}

Drug::Drug(string name, double cost, bool recipe, string country, int releaseform) :
	name(name), cost(cost), recipe(recipe), country(country), releaseform(releaseform) {}

Drug::Drug(const Drug& other) :
	name(other.name), cost(other.cost), recipe(other.recipe), country(other.country), releaseform(other.releaseform) {}

Drug::~Drug() {}




void Drug::print_name()
{
	cout << "Name: " << name << endl;
}


void Drug::print_cost()
{
	cout << "Cost: " << cost << endl;
}


void Drug::print_recipe()
{
	cout << "Recipe: " << (recipe ? "Yes" : "No") << endl;
}


void Drug::print_country()
{
	cout << "Country: " << country << endl;
}


void Drug::print_releaseform()
{
	cout << "Release Form: ";
	switch (releaseform)
	{
	case 1:
		cout << "Solid";
		break;
	case 2:
		cout << "Soft";
		break;
	case 3:
		cout << "Liquid";
		break;
	case 4:
		cout << "Gaseous";
		break;
	}
	cout << endl;
}





void Drug::redact_name(const string& newname)
{
	name = newname;
}

void Drug::redact_cost(const double& newcost)
{
	cost = newcost;
}

void Drug::redact_recipe()
{
	recipe = !recipe;
}

void Drug::redact_country(const string& newcountry)
{
	country = newcountry;
}

void Drug::redact_releaseform(const int& newform)
{
	releaseform = newform;
}




void Drug::maxcost(const Drug drugs[], int size, const string& country)
{
	double mcost = 0.0;
	string maxcostdrug;
	for (int i = 0; i < size; ++i)
	{
		if (drugs[i].country == country && drugs[i].cost > mcost)
		{
			mcost = drugs[i].cost;
			maxcostdrug = drugs[i].name;
		}
	}
	if (mcost > 0.0)
	{
		cout << "The most expensive drug in " << country << " is: " << maxcostdrug << " (Cost: " << mcost << ")" << endl;
	}
	else
	{
		cout << "No drugs found for " << country << endl;
	}
}


void Drug::ratiorecipe(const Drug drugs[], int size, const string& country)
{
	int recipecount = 0;
	int nonrecipecount = 0;

	for (int i = 0; i < size; ++i) {
		if (drugs[i].country == country)
		{
			if (drugs[i].recipe)
			{
				++recipecount;
			}
			else
			{
				++nonrecipecount;
			}
		}
	}

	if (recipecount > 0 || nonrecipecount > 0)
	{
		cout << "Recipe to non-recipe drug ratio in " << country << ": ";
		cout << recipecount << " : " << nonrecipecount << endl;
	}
	else
	{
		cout << "No drugs found for " << country << endl;
	}
}


void Drug::listdrugs(const Drug drugs[], int size, const int form)
{
	cout << "Drugs with release form " << form << ": " << " ";
	for (int i = 0; i < size; ++i)
	{
		if (drugs[i].releaseform == form)
		{
			cout << drugs[i].name << endl;
		}
	}
}




int main()
{
	const int numdrugs = 3;
	Drug drugs[numdrugs];

	drugs[0] = Drug("Aspirin", 5.99, false, "USA", 1);
	drugs[1] = Drug("Paracetamol", 8.49, false, "USA", 3);
	drugs[2] = Drug("Amoxicillin", 15.99, true, "Germany", 3);

	cout << "Before editing:" << endl << endl;

	for (int i = 0; i < numdrugs; ++i)
	{
		drugs[i].print_name();
		drugs[i].print_cost();
		drugs[i].print_recipe();
		drugs[i].print_country();
		drugs[i].print_releaseform();
		cout << endl;
	}

	drugs[1].redact_name("Askorutin");
	drugs[1].redact_cost(9.95);
	drugs[1].redact_recipe();
	drugs[1].redact_country("Russia");
	drugs[1].redact_releaseform(2);

	cout << "After editing:" << endl << endl;
	for (int i = 0; i < numdrugs; ++i)
	{
		drugs[i].print_name();
		drugs[i].print_cost();
		drugs[i].print_recipe();
		drugs[i].print_country();
		drugs[i].print_releaseform();
		cout << endl;
	}



	Drug::maxcost(drugs, numdrugs, "USA");
	Drug::ratiorecipe(drugs, numdrugs, "USA");
	Drug::listdrugs(drugs, numdrugs, 3);


	return 0;
}