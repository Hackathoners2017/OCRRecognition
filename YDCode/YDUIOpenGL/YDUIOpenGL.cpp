// YDUIOpenGL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "glut.h"
#include <iostream>
#include <fstream>
#include <string>

static int day = 500;
void myDisplay(void)
{
	glEnable(GL_DEPTH_TEST); //������Ȳ���

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�����Ȼ������ɫ����
	glDepthFunc(GL_LESS);
	glMatrixMode(GL_PROJECTION); //����ͶӰ����
	glLoadIdentity(); //���б任ǰͨ���ѵ�ǰ��������Ϊ��λ����
	gluPerspective(75,1,1,1000); //���ÿ��ӿռ䣬�õ�͸��Ч�������ӽǣ��߿�ȣ�������Ӿ��룬��Զ���Ӿ��룩
	glMatrixMode(GL_MODELVIEW); //���õ�ǰ�����ľ���Ϊ��ģ����ͼ����
	glLoadIdentity(); //�ѵ�ǰ��������Ϊ��λ����
	gluLookAt(0,-100,500,0,0,0,0,0,1); //�趨�۲��λ�ã��۲��λ�ã�Ŀ��λ�ã��۲����Ϸ���
	double dValue = 0;
	FILE *pFile = fopen("venus.asc","rb");
	if (NULL == pFile)
	{
		return ;
	}
	char ch[50];
	fseek(pFile,0,SEEK_SET);

	long length;
	fseek(pFile,0L,SEEK_END);
	length=ftell(pFile);
	fseek(pFile,0,SEEK_SET);
	glRotatef(day, 0.0f,1.0f,-0.0f);
	//glRotatef(0, 0.0f,1.0f,-0.0f);
	glBegin(GL_POINTS);
	int iValNumCount = 0;
	GLdouble glPnt3Val[3];
	while (1)
	{
		char chSingle = '0';
		int iCount = 0;
		fread(&chSingle,sizeof(char),1,pFile);
		memset(ch,0,sizeof(ch));
		bool bGetVal = false;
		while (((chSingle >= '0') &&(chSingle <= '9')) //������
			||(chSingle == '.')//��С����
			||(chSingle == '-')//�Ǹ���
			)
		{
			ch[iCount] = chSingle;
			iCount++;
			fread(&chSingle,sizeof(char),1,pFile);
			bGetVal = true;
		}
		if (bGetVal == true)
		{
			glPnt3Val[iValNumCount] = atof(ch);
			iValNumCount++;
		}
		if (chSingle == '\n')
		{
			if (iValNumCount == 3)
			{
				glVertex3d(glPnt3Val[0],glPnt3Val[1],glPnt3Val[2]);
			}
			else
			{
				break;
			}
			iValNumCount = 0;
			memset(glPnt3Val,0,sizeof(glPnt3Val));
		}
		//fread(&ch,sizeof(char),50,pFile);
		dValue = atof(ch);

		long curpos = ftell(pFile);
		if (curpos >= length)
		{
			break;
		}
	}
	fclose(pFile);
	glEnd();

	glutSwapBuffers();
	//glFlush();

}

void play()
{
	day+=5;
	if(day >= 360)
		day = 0;

	glutPostRedisplay();
}

void PlayAfterListen()
{
	if (true)
	{
		day+=5;
		if(day >= 360)
			day = 0;
	}
	glutPostRedisplay();
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(400,400);
	glutInitWindowSize(400,400);
	glutCreateWindow("study");

	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&PlayAfterListen);                // �¼��������

	glutMainLoop();
	return 0;
}

