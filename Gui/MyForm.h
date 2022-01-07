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
int sizeofprof = 0;

namespace Gui {

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
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
				sizeofprof = list_of_best[0].profs.size();//gets the number of professors in a table
				arr[0] = 1;
				arr[1] = 2;
				arr[2] = 3;

			}
			catch (...)
			{
				//cout << "Error handled: Incorrect file generation or Empty file/No possible schedule";
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ name1;
	private: System::Windows::Forms::Label^ name2;
	private: System::Windows::Forms::Label^ name3;
	private: System::Windows::Forms::Label^ name4;
	private: System::Windows::Forms::Label^ name5;
	private: System::Windows::Forms::Label^ course5;

	private: System::Windows::Forms::Label^ course4;

	private: System::Windows::Forms::Label^ course3;

	private: System::Windows::Forms::Label^ course2;

	private: System::Windows::Forms::Label^ course1;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->name1 = (gcnew System::Windows::Forms::Label());
			this->name2 = (gcnew System::Windows::Forms::Label());
			this->name3 = (gcnew System::Windows::Forms::Label());
			this->name4 = (gcnew System::Windows::Forms::Label());
			this->name5 = (gcnew System::Windows::Forms::Label());
			this->course5 = (gcnew System::Windows::Forms::Label());
			this->course4 = (gcnew System::Windows::Forms::Label());
			this->course3 = (gcnew System::Windows::Forms::Label());
			this->course2 = (gcnew System::Windows::Forms::Label());
			this->course1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->Location = System::Drawing::Point(212, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Schedule Next";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// name1
			// 
			this->name1->AutoSize = true;
			this->name1->Location = System::Drawing::Point(132, 84);
			this->name1->Name = L"name1";
			this->name1->Size = System::Drawing::Size(58, 20);
			this->name1->TabIndex = 1;
			this->name1->Text = L"name1";
			// 
			// name2
			// 
			this->name2->AutoSize = true;
			this->name2->Location = System::Drawing::Point(132, 104);
			this->name2->Name = L"name2";
			this->name2->Size = System::Drawing::Size(58, 20);
			this->name2->TabIndex = 2;
			this->name2->Text = L"name2";
			// 
			// name3
			// 
			this->name3->AutoSize = true;
			this->name3->Location = System::Drawing::Point(132, 124);
			this->name3->Name = L"name3";
			this->name3->Size = System::Drawing::Size(58, 20);
			this->name3->TabIndex = 3;
			this->name3->Text = L"name3";
			// 
			// name4
			// 
			this->name4->AutoSize = true;
			this->name4->Location = System::Drawing::Point(132, 144);
			this->name4->Name = L"name4";
			this->name4->Size = System::Drawing::Size(58, 20);
			this->name4->TabIndex = 4;
			this->name4->Text = L"name4";
			// 
			// name5
			// 
			this->name5->AutoSize = true;
			this->name5->Location = System::Drawing::Point(132, 164);
			this->name5->Name = L"name5";
			this->name5->Size = System::Drawing::Size(58, 20);
			this->name5->TabIndex = 5;
			this->name5->Text = L"name5";
			// 
			// course5
			// 
			this->course5->AutoSize = true;
			this->course5->Location = System::Drawing::Point(29, 164);
			this->course5->Name = L"course5";
			this->course5->Size = System::Drawing::Size(66, 20);
			this->course5->TabIndex = 10;
			this->course5->Text = L"course5";
			// 
			// course4
			// 
			this->course4->AutoSize = true;
			this->course4->Location = System::Drawing::Point(29, 144);
			this->course4->Name = L"course4";
			this->course4->Size = System::Drawing::Size(66, 20);
			this->course4->TabIndex = 9;
			this->course4->Text = L"course4";
			// 
			// course3
			// 
			this->course3->AutoSize = true;
			this->course3->Location = System::Drawing::Point(29, 124);
			this->course3->Name = L"course3";
			this->course3->Size = System::Drawing::Size(66, 20);
			this->course3->TabIndex = 8;
			this->course3->Text = L"course3";
			// 
			// course2
			// 
			this->course2->AutoSize = true;
			this->course2->Location = System::Drawing::Point(29, 104);
			this->course2->Name = L"course2";
			this->course2->Size = System::Drawing::Size(66, 20);
			this->course2->TabIndex = 7;
			this->course2->Text = L"course2";
			// 
			// course1
			// 
			this->course1->AutoSize = true;
			this->course1->Location = System::Drawing::Point(29, 84);
			this->course1->Name = L"course1";
			this->course1->Size = System::Drawing::Size(66, 20);
			this->course1->TabIndex = 6;
			this->course1->Text = L"course1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 338);
			this->Controls->Add(this->course5);
			this->Controls->Add(this->course4);
			this->Controls->Add(this->course3);
			this->Controls->Add(this->course2);
			this->Controls->Add(this->course1);
			this->Controls->Add(this->name5);
			this->Controls->Add(this->name4);
			this->Controls->Add(this->name3);
			this->Controls->Add(this->name2);
			this->Controls->Add(this->name1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"BU Course Scheduler";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
		if (sizeofprof == 4)
		{
			name1->Text = gcnew String(list_of_best[countInst].profs[0]->getName().data());
			course1->Text = gcnew String(list_of_best[countInst].profs[0]->getCourseID().data());

			name2->Text = gcnew String(list_of_best[countInst].profs[1]->getName().data());
			course2->Text = gcnew String(list_of_best[countInst].profs[1]->getCourseID().data());

			name3->Text = gcnew String(list_of_best[countInst].profs[2]->getName().data());
			course3->Text = gcnew String(list_of_best[countInst].profs[2]->getCourseID().data());

			name4->Text = gcnew String(list_of_best[countInst].profs[3]->getName().data());
			course4->Text = gcnew String(list_of_best[countInst].profs[3]->getCourseID().data());

			name5->Text = "";
			course5->Text = "";
		}
		if (sizeofprof == 5)
		{
			name1->Text = gcnew String(list_of_best[countInst].profs[0]->getName().data());
			name2->Text = gcnew String(list_of_best[countInst].profs[1]->getName().data());
			name3->Text = gcnew String(list_of_best[countInst].profs[2]->getName().data());
			name4->Text = gcnew String(list_of_best[countInst].profs[3]->getName().data());
			name5->Text = gcnew String(list_of_best[countInst].profs[4]->getName().data());;
		}
		countInst++;
	}

};
}
