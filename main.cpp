#include "emp.h"
#include "Member.h"
#include "app.h"

void doTask();
void join();
void program_exit(FILE *out_fp);

FILE *in_fp, *out_fp;

int main()
{
    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}

void doTask()
{
    int menu_level_1 = 0, menu_level_2 = 0, type = 0;
    int is_program_exit = 0;
    CpMem curCpMem;
    CmMem curCmMem;
    CpMem cpMembers[100];
    CmMem cmMembers[100];
    int cpMemIndex = 0;
    int cmMemIndex = 0;
    EmpInfo empInfo[100];
    int empInfoIndex = 0;
    AppInfo appInfo[100];
    int appInfoIndex = 0;

    while (!is_program_exit)
    {
        fscanf(in_fp, "%d %d", &menu_level_1, &menu_level_2);

        switch (menu_level_1)
        {
        case 1: // 회원 가입
            switch (menu_level_2)
            {
            case 1:
                fscanf(in_fp, "%d", &type);
                signIn(type, in_fp, out_fp, cpMembers, cmMembers, cpMemIndex, cmMemIndex);
                break;
            }
            break;
        case 2:
            switch (menu_level_2)
            {
            case 1: // 로그인
                // curMem = login(in_fp, out_fp, members);
                login(in_fp, out_fp, cpMembers, cmMembers, curCpMem, curCmMem, cpMemIndex, cmMemIndex);
                break;
            case 2: // 로그아웃
                logout(out_fp, curCpMem, curCmMem);
                break;
            }
            break;

        case 3:
            switch (menu_level_2)
            {
            case 1: // 채용 정보 추가
                empInfo[empInfoIndex++] = addEmp(in_fp, out_fp, empInfo, empInfoIndex, curCpMem);
                break;
            case 2: // 채용 정보 조회
                showEmps(out_fp, empInfo, empInfoIndex, curCpMem);
                break;
            }
            break;
        case 4:
            // switch (menu_level_2)
            // {
            // case 1: //
            //     addApp(in_fp, out_fp, appInfo, appInfoIndex, curMem);
            //     break;
            // case 2:
            //     showApps(out_fp, appInfo, appInfoIndex, curMem);
            //     break;
            // }
            break;
        case 6:
            switch (menu_level_2)
            {
            case 1:
                program_exit(out_fp);
                is_program_exit = 1;
                break;
            }
        }
        fprintf(out_fp, "\n");
    }
}

void program_exit(FILE *out_fp)
{
    fprintf(out_fp, "6.1. 종료\n");
    fclose(in_fp);
    fclose(out_fp);
}
