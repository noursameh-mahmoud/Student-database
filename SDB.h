#include "STD.h"
#ifndef SDB_H_
#define SDB_H_
typedef struct SimpleDb
{
	u32 Student_ID;
	u32 Student_Year;
	u32 Course1_ID;
    u32 Course1_grade;
    u32 Course2_ID;
    u32 Course2_grade;
    u32 Course3_ID;
    u32 Course3_grade;
} student;
void SDB_APP();
void SDB_Action(u8 choice);
bool SDB_IsFull();
u8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry(u32 id);
bool SDB_ReadEntry(u32 id);
void SDB_GetList(u8*count, u32*list);
bool SDB_IsIDExist(u32 id);
extern u8 count;
extern u32 list[10];
#endif