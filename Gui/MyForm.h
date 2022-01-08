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
	private: System::Windows::Forms::Label^ rating5;
	private: System::Windows::Forms::Label^ rating4;
	private: System::Windows::Forms::Label^ rating3;
	private: System::Windows::Forms::Label^ rating2;
	private: System::Windows::Forms::Label^ rating1;
	private: System::Windows::Forms::Label^ avgrating;
	private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ stime5;
private: System::Windows::Forms::Label^ stime4;
private: System::Windows::Forms::Label^ stime3;
private: System::Windows::Forms::Label^ stime2;
private: System::Windows::Forms::Label^ stime1;
private: System::Windows::Forms::Label^ etime5;
private: System::Windows::Forms::Label^ etime4;
private: System::Windows::Forms::Label^ etime3;
private: System::Windows::Forms::Label^ etime2;
private: System::Windows::Forms::Label^ etime1;
private: System::Windows::Forms::Label^ days5;
private: System::Windows::Forms::Label^ days4;
private: System::Windows::Forms::Label^ days3;
private: System::Windows::Forms::Label^ days2;
private: System::Windows::Forms::Label^ days1;








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
			this->rating5 = (gcnew System::Windows::Forms::Label());
			this->rating4 = (gcnew System::Windows::Forms::Label());
			this->rating3 = (gcnew System::Windows::Forms::Label());
			this->rating2 = (gcnew System::Windows::Forms::Label());
			this->rating1 = (gcnew System::Windows::Forms::Label());
			this->avgrating = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->stime5 = (gcnew System::Windows::Forms::Label());
			this->stime4 = (gcnew System::Windows::Forms::Label());
			this->stime3 = (gcnew System::Windows::Forms::Label());
			this->stime2 = (gcnew System::Windows::Forms::Label());
			this->stime1 = (gcnew System::Windows::Forms::Label());
			this->etime5 = (gcnew System::Windows::Forms::Label());
			this->etime4 = (gcnew System::Windows::Forms::Label());
			this->etime3 = (gcnew System::Windows::Forms::Label());
			this->etime2 = (gcnew System::Windows::Forms::Label());
			this->etime1 = (gcnew System::Windows::Forms::Label());
			this->days5 = (gcnew System::Windows::Forms::Label());
			this->days4 = (gcnew System::Windows::Forms::Label());
			this->days3 = (gcnew System::Windows::Forms::Label());
			this->days2 = (gcnew System::Windows::Forms::Label());
			this->days1 = (gcnew System::Windows::Forms::Label());
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
			// rating5
			// 
			this->rating5->AutoSize = true;
			this->rating5->Location = System::Drawing::Point(225, 164);
			this->rating5->Name = L"rating5";
			this->rating5->Size = System::Drawing::Size(58, 20);
			this->rating5->TabIndex = 15;
			this->rating5->Text = L"rating5";
			// 
			// rating4
			// 
			this->rating4->AutoSize = true;
			this->rating4->Location = System::Drawing::Point(225, 144);
			this->rating4->Name = L"rating4";
			this->rating4->Size = System::Drawing::Size(58, 20);
			this->rating4->TabIndex = 14;
			this->rating4->Text = L"rating4";
			// 
			// rating3
			// 
			this->rating3->AutoSize = true;
			this->rating3->Location = System::Drawing::Point(225, 124);
			this->rating3->Name = L"rating3";
			this->rating3->Size = System::Drawing::Size(58, 20);
			this->rating3->TabIndex = 13;
			this->rating3->Text = L"rating3";
			// 
			// rating2
			// 
			this->rating2->AutoSize = true;
			this->rating2->Location = System::Drawing::Point(225, 104);
			this->rating2->Name = L"rating2";
			this->rating2->Size = System::Drawing::Size(58, 20);
			this->rating2->TabIndex = 12;
			this->rating2->Text = L"rating2";
			// 
			// rating1
			// 
			this->rating1->AutoSize = true;
			this->rating1->Location = System::Drawing::Point(225, 84);
			this->rating1->Name = L"rating1";
			this->rating1->Size = System::Drawing::Size(58, 20);
			this->rating1->TabIndex = 11;
			this->rating1->Text = L"rating1";
			// 
			// avgrating
			// 
			this->avgrating->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->avgrating->AutoSize = true;
			this->avgrating->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->avgrating->Location = System::Drawing::Point(208, 230);
			this->avgrating->Name = L"avgrating";
			this->avgrating->Size = System::Drawing::Size(133, 20);
			this->avgrating->TabIndex = 16;
			this->avgrating->Text = L"Average Rating";
			this->avgrating->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->avgrating->UseMnemonic = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(185, 201);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(172, 26);
			this->textBox1->TabIndex = 17;
			this->textBox1->Text = L"  Total Average Rating";
			// 
			// stime5
			// 
			this->stime5->AutoSize = true;
			this->stime5->Location = System::Drawing::Point(306, 164);
			this->stime5->Name = L"stime5";
			this->stime5->Size = System::Drawing::Size(56, 20);
			this->stime5->TabIndex = 22;
			this->stime5->Text = L"stime5";
			// 
			// stime4
			// 
			this->stime4->AutoSize = true;
			this->stime4->Location = System::Drawing::Point(306, 144);
			this->stime4->Name = L"stime4";
			this->stime4->Size = System::Drawing::Size(56, 20);
			this->stime4->TabIndex = 21;
			this->stime4->Text = L"stime4";
			// 
			// stime3
			// 
			this->stime3->AutoSize = true;
			this->stime3->Location = System::Drawing::Point(306, 124);
			this->stime3->Name = L"stime3";
			this->stime3->Size = System::Drawing::Size(56, 20);
			this->stime3->TabIndex = 20;
			this->stime3->Text = L"stime3";
			// 
			// stime2
			// 
			this->stime2->AutoSize = true;
			this->stime2->Location = System::Drawing::Point(306, 104);
			this->stime2->Name = L"stime2";
			this->stime2->Size = System::Drawing::Size(56, 20);
			this->stime2->TabIndex = 19;
			this->stime2->Text = L"stime2";
			// 
			// stime1
			// 
			this->stime1->AutoSize = true;
			this->stime1->Location = System::Drawing::Point(306, 84);
			this->stime1->Name = L"stime1";
			this->stime1->Size = System::Drawing::Size(56, 20);
			this->stime1->TabIndex = 18;
			this->stime1->Text = L"stime1";
			// 
			// etime5
			// 
			this->etime5->AutoSize = true;
			this->etime5->Location = System::Drawing::Point(368, 164);
			this->etime5->Name = L"etime5";
			this->etime5->Size = System::Drawing::Size(57, 20);
			this->etime5->TabIndex = 27;
			this->etime5->Text = L"etime5";
			// 
			// etime4
			// 
			this->etime4->AutoSize = true;
			this->etime4->Location = System::Drawing::Point(368, 144);
			this->etime4->Name = L"etime4";
			this->etime4->Size = System::Drawing::Size(57, 20);
			this->etime4->TabIndex = 26;
			this->etime4->Text = L"etime4";
			// 
			// etime3
			// 
			this->etime3->AutoSize = true;
			this->etime3->Location = System::Drawing::Point(368, 124);
			this->etime3->Name = L"etime3";
			this->etime3->Size = System::Drawing::Size(57, 20);
			this->etime3->TabIndex = 25;
			this->etime3->Text = L"etime3";
			// 
			// etime2
			// 
			this->etime2->AutoSize = true;
			this->etime2->Location = System::Drawing::Point(368, 104);
			this->etime2->Name = L"etime2";
			this->etime2->Size = System::Drawing::Size(57, 20);
			this->etime2->TabIndex = 24;
			this->etime2->Text = L"etime2";
			// 
			// etime1
			// 
			this->etime1->AutoSize = true;
			this->etime1->Location = System::Drawing::Point(368, 84);
			this->etime1->Name = L"etime1";
			this->etime1->Size = System::Drawing::Size(57, 20);
			this->etime1->TabIndex = 23;
			this->etime1->Text = L"etime1";
			// 
			// days5
			// 
			this->days5->AutoSize = true;
			this->days5->Location = System::Drawing::Point(454, 164);
			this->days5->Name = L"days5";
			this->days5->Size = System::Drawing::Size(51, 20);
			this->days5->TabIndex = 32;
			this->days5->Text = L"days5";
			// 
			// days4
			// 
			this->days4->AutoSize = true;
			this->days4->Location = System::Drawing::Point(454, 144);
			this->days4->Name = L"days4";
			this->days4->Size = System::Drawing::Size(51, 20);
			this->days4->TabIndex = 31;
			this->days4->Text = L"days4";
			// 
			// days3
			// 
			this->days3->AutoSize = true;
			this->days3->Location = System::Drawing::Point(454, 124);
			this->days3->Name = L"days3";
			this->days3->Size = System::Drawing::Size(51, 20);
			this->days3->TabIndex = 30;
			this->days3->Text = L"days3";
			// 
			// days2
			// 
			this->days2->AutoSize = true;
			this->days2->Location = System::Drawing::Point(454, 104);
			this->days2->Name = L"days2";
			this->days2->Size = System::Drawing::Size(51, 20);
			this->days2->TabIndex = 29;
			this->days2->Text = L"days2";
			// 
			// days1
			// 
			this->days1->AutoSize = true;
			this->days1->Location = System::Drawing::Point(454, 84);
			this->days1->Name = L"days1";
			this->days1->Size = System::Drawing::Size(51, 20);
			this->days1->TabIndex = 28;
			this->days1->Text = L"days1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 338);
			this->Controls->Add(this->days5);
			this->Controls->Add(this->days4);
			this->Controls->Add(this->days3);
			this->Controls->Add(this->days2);
			this->Controls->Add(this->days1);
			this->Controls->Add(this->etime5);
			this->Controls->Add(this->etime4);
			this->Controls->Add(this->etime3);
			this->Controls->Add(this->etime2);
			this->Controls->Add(this->etime1);
			this->Controls->Add(this->stime5);
			this->Controls->Add(this->stime4);
			this->Controls->Add(this->stime3);
			this->Controls->Add(this->stime2);
			this->Controls->Add(this->stime1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->avgrating);
			this->Controls->Add(this->rating5);
			this->Controls->Add(this->rating4);
			this->Controls->Add(this->rating3);
			this->Controls->Add(this->rating2);
			this->Controls->Add(this->rating1);
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
		avgrating->Text = System::Convert::ToString(list_of_best[countInst].average_rating);
		if (sizeofprof == 4)
		{
			name1->Text = gcnew String(list_of_best[countInst].profs[0]->getName().data());
			course1->Text = gcnew String(list_of_best[countInst].profs[0]->getCourseID().data());
			rating1->Text = System::Convert::ToString(list_of_best[countInst].profs[0]->getRating());
			stime1->Text = System::Convert::ToString(list_of_best[countInst].profs[0]->getStartTime());
			etime1->Text = System::Convert::ToString(list_of_best[countInst].profs[0]->getEndTime());
			days1->Text = gcnew String(list_of_best[countInst].profs[0]->getDay().data());

			name2->Text = gcnew String(list_of_best[countInst].profs[1]->getName().data());
			course2->Text = gcnew String(list_of_best[countInst].profs[1]->getCourseID().data());
			rating2->Text = System::Convert::ToString(list_of_best[countInst].profs[1]->getRating());
			stime2->Text = System::Convert::ToString(list_of_best[countInst].profs[1]->getStartTime());
			etime2->Text = System::Convert::ToString(list_of_best[countInst].profs[1]->getEndTime());
			days2->Text = gcnew String(list_of_best[countInst].profs[1]->getDay().data());

			name3->Text = gcnew String(list_of_best[countInst].profs[2]->getName().data());
			course3->Text = gcnew String(list_of_best[countInst].profs[2]->getCourseID().data());
			rating3->Text = System::Convert::ToString(list_of_best[countInst].profs[2]->getRating());
			stime3->Text = System::Convert::ToString(list_of_best[countInst].profs[2]->getStartTime());
			etime3->Text = System::Convert::ToString(list_of_best[countInst].profs[2]->getEndTime());
			days3->Text = gcnew String(list_of_best[countInst].profs[2]->getDay().data());

			name4->Text = gcnew String(list_of_best[countInst].profs[3]->getName().data());
			course4->Text = gcnew String(list_of_best[countInst].profs[3]->getCourseID().data());
			rating4->Text = System::Convert::ToString(list_of_best[countInst].profs[3]->getRating());
			stime4->Text = System::Convert::ToString(list_of_best[countInst].profs[3]->getStartTime());
			etime4->Text = System::Convert::ToString(list_of_best[countInst].profs[3]->getEndTime());
			days4->Text = gcnew String(list_of_best[countInst].profs[3]->getDay().data());

			name5->Text = "";
			course5->Text = "";
			rating5->Text = "";
			stime5->Text = "";
			etime5->Text = "";
			days5->Text = "";
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
