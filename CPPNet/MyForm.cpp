#include "MyForm.h"
using namespace System;

using namespace System::Windows::Forms;

[STAThread]

void main()
{
	

		/*
		VariadicTable <string, string, double, int, int, string> vt({ "CourseId","Professor","Rating","StartTime","EndTime", "Days" });

		cout << "BEST POSSIBLE SCHEDULE" << endl;
		cout << "With an average professor rating of: " << list_of_best[0].average_rating << endl;
		cout << "The Classes are: " << endl;
		for (Professor* professors : list_of_best[0].profs)
		{
			vt.addRow(professors->getCourseID(), professors->getName(), professors->getRating(), professors->getStartTime(), professors->getEndTime(), professors->getDay());
		}

		vt.print(cout);



		cout << "_______________________________________________________" << endl;

		char choice;
		int count_best = 1;
		cout << "Do You Wish To See The Next Best Schedule? (Y/Any other character)" << endl;
		cin >> choice;

		while (choice == 'Y')
		{
			VariadicTable <string, string, double, int, int, string> vt({ "CourseId","Professor","Rating","StartTime","EndTime", "Days" });
			cout << "At Position - " << (count_best + 1) << " ,the rating is " << list_of_best[count_best].average_rating << endl;
			for (Professor* professors : list_of_best[count_best].profs)
			{
				vt.addRow(professors->getCourseID(), professors->getName(), professors->getRating(), professors->getStartTime(), professors->getEndTime(), professors->getDay());
			}
			vt.print(cout);
			cout << "_______________________________________________________" << endl;
			count_best++;
			if (count_best <= list_of_best.size())
			{
				cout << "Do You Wish To See The Next Best Schedule? (Y/Any other character)" << endl;
				cin >> choice;
			}
			else
				break;
		}
		*/
		Application::EnableVisualStyles();

		Application::SetCompatibleTextRenderingDefault(false);

		CPPNet::MyForm form;

		Application::Run(% form);
	

}
