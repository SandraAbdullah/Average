#include<iostream>
#include<vector>

using namespace std;

short ReadPositiveNumber(string message)
{
	short Number;
	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number<0 || Number>500);

	return Number;
}

void ReadGrades(short NumberOfStudents, vector<float> &vGrades)
{
	float Grade;
	cout << "\nPlease enter student grade:\n";
	for (short i = 0; i < NumberOfStudents; i++)
	{
		do
		{
			cout << "Student #" << i+1 << " grade is: ";
			cin >> Grade;
		} while (Grade<0 || Grade>100);
		
		vGrades.push_back(Grade);
		cout << endl;
	}
}

float SumOfGrades(short NumberOfStudents, vector<float>& vGrades)
{
	float sum = 0;
	for (float &Grade : vGrades)
	{
		sum += Grade;
	}
	return sum;
}

float CalculateAverage(short NumberOfStudents, vector<float>& vGrades)
{
	return (SumOfGrades(NumberOfStudents, vGrades) / NumberOfStudents);
}

void CheckGrade(short NumberOfStudents, vector<float>& vGrades)
{
	for (float& Grade : vGrades)
	{
		if (Grade >= CalculateAverage(NumberOfStudents, vGrades))
			cout << Grade << " ";
	}
}

int main()
{
	short NumberOfStudents = ReadPositiveNumber("Please enter number of students (1-500)");

	vector<float> vGrades;

	ReadGrades(NumberOfStudents, vGrades);

	cout << "Grades Average = " << CalculateAverage(NumberOfStudents, vGrades) << endl;

	cout << "\nGrades Above or Equal Average are :";
	CheckGrade(NumberOfStudents, vGrades);

	system("pause > 0");
}
