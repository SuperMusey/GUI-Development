#pragma once

#include "Professor.h"
#include "FileIn.h"
#include "Course.h"

bool compareByRating(const rating_prof& i, const rating_prof& j)
{
	return i.average_rating > j.average_rating;
}
int arr[3];
vector <rating_prof> list_of_best = {};
int countInst = 0;
namespace CPPNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int Arr(int arr[])
		{
			return arr[0];
		}
		MyForm(void)
		{
			InitializeComponent();
			try
			{
				Professor prof;
				Course course;
				vector <vector<Professor*>> courseslist;
				FileIn inputFile;
				string fileName = "test.csv";
				inputFile.ReadFromFile(fileName);

				vector <string> course_id = inputFile.getCourseId();
				vector <string> prof_name = inputFile.getName();
				vector <double> rating = inputFile.getRating();
				vector <int> class_start_time = inputFile.getStartTime();
				vector <int> class_end_time = inputFile.getEndTime();
				vector <vector<char>> days_in_file = inputFile.getDays();

				int size = course_id.size();
				if (size == 0)
				{
					throw;
				}

				vector <string> cid_copy = course_id;
				sort(cid_copy.begin(), cid_copy.end());
				cid_copy.erase(unique(cid_copy.begin(), cid_copy.end()), cid_copy.end());
				int uniqueCourse = cid_copy.size();

				for (int i = 0; i < uniqueCourse; i++)
				{
					vector <Professor*> prof_temp;
					for (int j = 0; j < size; j++)
					{
						if (cid_copy[i] == course_id[j])
						{
							prof.AddNode(course_id[j], i, prof_name[j], rating[j], class_start_time[j], class_end_time[j], days_in_file[j], prof_temp);
						}
					}
					courseslist.push_back(prof_temp);
				}

				//vector <rating_prof> list_of_best = {};
				list_of_best = course.CalcAverages(courseslist);
				if (list_of_best.capacity() == 0)
				{
					throw;
				}

				sort(list_of_best.begin(), list_of_best.end(), compareByRating);
				arr[0] = 1;
				arr[1] = 2;
				arr[2] = 3;

			}
			catch (...)
			{
				//cout << "Error handled: Incorrect file generation or Empty file/No possible schedule";
			}

		}
		/*int ArrayTest()
		   {
			   int arr[3] = { 1,2,3 };
			   return arr[0];
		   }*/

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{

			}
		}
	
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(706, 407);
			this->Name = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = System::Convert::ToString(countInst);
		label2->Text = System::Convert::ToString(list_of_best[0].average_rating);
		label3->Text = "Morrison";
		countInst++;
	}
	};
}
