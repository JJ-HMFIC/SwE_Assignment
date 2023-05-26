#include "seap.h"

using namespace std;

void viewEmp(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex)
{
	ViewEmployUI viewEmployUI;
	ViewEmploy viewEmploy;

	viewEmployUI.searchEmploy(in_fp, out_fp, empInfo, empInfoIndex);
}

void ViewEmployUI::searchEmploy(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex)
{
	ViewEmploy viewEmploy;
	char company_name[MAX_STRING];

	fprintf(out_fp, "4.1. 채용 정보 검색 \n");
	fscanf(in_fp, "%s", company_name);

	viewEmploy.showEmploy(in_fp, out_fp, empInfoIndex, company_name, empInfo);
}

void ViewEmploy::showEmploy(FILE *in_fp, FILE *out_fp, int &empInfoIndex, const char *cname, EmpInfo *myEmpInfo)
{

	for (int i = 0; i < empInfoIndex; i++)
	{
		if (strcmp(myEmpInfo[i].getCpName(), cname) == 0)
		{
			fprintf(out_fp, "> %s %s %s %s %s\n", myEmpInfo[i].getCpName(), myEmpInfo[i].getSsn(), myEmpInfo[i].getJob(), myEmpInfo[i].getNum(), myEmpInfo[i].getDate());
		}
	}
}

AppInfo applyEmp(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, int &empInfoIndex, int &applyInfoIndex, CmMem &curMem)
{
	ApplyEmployUI applyEmpUI = ApplyEmployUI();
	ApplyEmploy applyEmp = ApplyEmploy();

	fprintf(out_fp, "4.2. 채용 지원\n");

	return applyEmpUI.selectApply(in_fp, out_fp, empInfo, applyEmp, empInfoIndex, applyInfoIndex, curMem);
}

AppInfo ApplyEmployUI::selectApply(FILE *in_fp, FILE *out_fp, EmpInfo *empInfo, ApplyEmploy &applyEmp, int &empInfoIndex, int &applyInfoIndex, CmMem &curMem)
{
	char *cpName = new char[MAX_STRING];
	char *job = new char[MAX_STRING];
	char *ssn = new char[MAX_STRING];
	char *num = new char[MAX_STRING];
	char *date = new char[MAX_STRING];
	fscanf(in_fp, "%s", ssn);

	EmpInfo *myEmpInfo = new EmpInfo[empInfoIndex];
	AppInfo *myApplyInfo = new AppInfo[applyInfoIndex];
	for (int i = 0; i < empInfoIndex; i++)
	{
		if (strcmp(empInfo[i].getSsn(), ssn) == 0)
		{
			cpName = empInfo[i].getCpName();
			ssn = empInfo[i].getSsn();
			job = empInfo[i].getJob();
			num = empInfo[i].getNum();
			date = empInfo[i].getDate();
			fprintf(out_fp, "> %s %s %s\n", cpName, ssn, job);
			break;
		}
	}

	return applyEmp.addNewMember(cpName, ssn, job, num, date, curMem);
}

AppInfo ApplyEmploy::addNewMember(char *cpName, char *ssn, char *job, char *num, char *date, CmMem &curMem)
{
	return AppInfo(curMem.getID(), cpName, ssn, job, num, date);
}
