#include"pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<fstream>
#include<stdio.h> 
#include<stdlib.h> 

using namespace std;

class Phone
{
	private:

		string brand;
		string model;
		string color;
		float price;
		int memory;
		int diagonal;
		bool sim;
		int year;

	public:

		void set_brand(string brand) { this->brand=brand; }
		void set_model(string model) { this->model=model; }
		void set_color(string color) { this->color=color; }
		void set_price(float price) { this->price=price; }
		void set_memory(int memory) { this->memory=memory; }
		void set_diagonal(int diagonal) { this->diagonal=diagonal; }
		void set_sim(bool sim) { this->sim=sim; }
		void set_year(int year) { this->year=year; }

		string get_brand() { return brand; }
		string get_model() { return model; }
		string get_color() { return color; }
		float get_price() { return price; }
		int get_memory() { return memory; }
		int get_diagonal() { return diagonal; }
		bool get_sim() { return sim; }
		int get_year() { return year; }

		static bool compare_brand(const Phone& phone, const Phone& phone1) { return phone.brand<phone1.brand; }
		static bool compare_brand_year(const Phone& phone, const Phone& phone1) { return phone.brand<phone1.brand && phone.year<phone1.year; }
		static bool compare_brand_model_diagonal(const Phone& phone, const Phone& phone1) { return phone.brand<phone1.brand && phone.model<phone1.model && phone.diagonal<phone1.diagonal; }

		bool operator ==(const Phone& phone)
		{
			if(brand==phone.brand && model==phone.model) { return true; }
			return false;
		}
};

void save_to_file(Phone phone, string file_name)
{
	ofstream my_file(file_name.c_str(), ios_base::app);
	my_file<<phone.get_brand();
	my_file<<phone.get_model();
	my_file<<phone.get_color();
	my_file<<phone.get_price();
	my_file<<phone.get_memory();
	my_file<<phone.get_diagonal();
	my_file<<phone.get_sim();
	my_file<<phone.get_year()<<endl;
}

void ask_for_save_to_file(Phone phone, int rpt)
{
	int choice;
	cout<<"1.Do you want to save the info to file? "<<endl;
	cin>>choice;

	switch(choice)
	{
		case 1: 
		{ 
			save_to_file(phone, "text.txt");
			break;
		}

		case 2: 
		{
			rpt=1;
			break;
		}
	}
}

void set_Phone(Phone &phone)
{
	int memory, diagonal, year;
	float price; bool sim;
	string brand, model, color;

	cout<<"Enter brand."<<endl;
	cin>>brand;
	phone.set_brand(brand);

	cout<<"Enter model."<<endl;
	cin>>model;
	phone.set_model(model);

	cout<<"Enter color."<<endl;
	cin>>color;
	phone.set_color(color);

	cout<<"Enter price."<<endl;
	cin>>price;
	phone.set_price(price);

	cout<<"Enter memory."<<endl;
	cin>>memory;
	phone.set_memory(memory);

	cout<<"Enter diagonal."<<endl;
	cin>>diagonal;
	phone.set_diagonal(diagonal);

	cout<<"Enter sim."<<endl;
	cin>>sim;
	phone.set_sim(sim);

	cout<<"Enter year."<<endl;
	cin>>year;
	phone.set_year(year);
}

void show_all_phones(vector<Phone>&phone)
{
	for(size_t i=0; i<phone.size(); i++)
	{
		cout<<"The brand is: "<<phone[i].get_brand()<<endl;
		cout<<"The model is: "<<phone[i].get_model()<<endl;
		cout<<"The color is: "<<phone[i].get_color()<<endl;
		cout<<"The price is: "<<phone[i].get_price()<<endl;
		cout<<"The memory is: "<<phone[i].get_memory()<<endl;
		cout<<"The diagonal is: "<<phone[i].get_diagonal()<<endl;
		cout<<"The sim is: "<<phone[i].get_sim()<<endl;
		cout<<"The year is: "<<phone[i].get_year()<<endl<<endl;
	}
}

int main(void)
{
	vector<Phone>vector_phones;
	int choice, number_of_phones, return_to_main_menu=0, memory, diagonal, year;
	float price; 
	bool sim;
	string brand, model, color;

	do 
	{
		system("CLS");
		cout<<"1.Add one new phone.\n"
			<<"2.Add several new phones.\n"
			<<"3.Show all phones.\n"
			<<"4.Add new data for a phone.\n"
			<<"5.Sell a phone.\n"
			<<"6.Show all phones in order(brand).\n"
			<<"7.Show all phones in order(brand, years).\n"
			<<"8.Show all phones in order(brand, model, diagonal).\n"
			<<"9.Exit \n";

		cin>>choice;
		Phone phone;

		switch(choice)
		{
			case 1:
			{
				set_Phone(phone);

				if(find(vector_phones.begin(), vector_phones.end(), phone)!=vector_phones.end()) { cout<<"Already exists!"<<endl; }

				else 
				{ 
					vector_phones.push_back(phone);
					ask_for_save_to_file(phone, return_to_main_menu);
				}

				break;
			}

			case 2:
			{
				cout<<"How many phones?";
				cin>>number_of_phones;

				while(number_of_phones>100)
				{ 
					cout<<"How many phones?";
					cin>>number_of_phones;
				}

				for(size_t i=0; i<number_of_phones; i++)
				{
					Phone phone;
					set_Phone(phone);

					if(find(vector_phones.begin(), vector_phones.end(), phone)!=vector_phones.end()) { cout<<"Already exists!"<<endl; }

					else 
					{
						vector_phones.push_back(phone);
						ask_for_save_to_file(phone, return_to_main_menu);
					}
				}
				break;
			}

			case 3: 
			{ 
				show_all_phones(vector_phones);
				break;
			}

			case 4:
			{
				cout<<"Enter brand."<<endl;
				cin>>brand;
				cout<<"Enter model."<<endl;
				cin>>model;

				for(size_t i=0; i<vector_phones.size(); i++)
				{
					if(brand==vector_phones[i].get_brand() && model==vector_phones[i].get_model())
					{
						cout<<"Enter color."<<endl;
						cin>>color;
						vector_phones[i].set_color(color);

						cout<<"Enter price."<<endl;
						cin>>price;
						vector_phones[i].set_price(price);

						cout<<"Enter memory."<<endl;
						cin>>memory;
						vector_phones[i].set_memory(memory);

						cout<<"Enter diagonal."<<endl;
						cin>>diagonal;
						vector_phones[i].set_diagonal(diagonal);

						cout<<"Enter sim."<<endl;
						cin>>sim;
						vector_phones[i].set_sim(sim);

						cout<<"Enter year."<<endl;
						cin>>year;
						vector_phones[i].set_year(year);
					}
				}
				break;
			}

			case 5:
			{
				cout<<"Enter brand."<<endl;
				cin>>brand;
				cout<<"Enter model."<<endl;
				cin>>model;

				for(size_t i=0; i<vector_phones.size(); i++)
				{
					if(brand==vector_phones[i].get_brand() && model==vector_phones[i].get_model()) { vector_phones.erase(vector_phones.begin()+i); }
					else cout<<"Nope!"<<endl;
				}
				break;
			}

			case 6:
			{
				sort(vector_phones.begin(), vector_phones.end(), Phone::compare_brand);
				show_all_phones(vector_phones);
				break;
			}

			case 7:
			{
				sort(vector_phones.begin(), vector_phones.end(), Phone::compare_brand_year);
				show_all_phones(vector_phones);
				break;
			}

			case 8:
			{
				sort(vector_phones.begin(), vector_phones.end(), Phone::compare_brand_model_diagonal);
				show_all_phones(vector_phones);
				break;
			}

			case 9: 
			{
				exit(0); 
				break; 
			}
		}

		cout<<"Would you like to return to the menu? 1.Yes 2.No"; 
		cin>>return_to_main_menu;

	}
	while(return_to_main_menu==1);

	system("pause");
}