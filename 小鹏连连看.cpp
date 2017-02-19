#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<easyx.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>


struct player
{
	char mingzi[8];
	int scores; 
}jingsu[5],chuangguan[5],jingsux,chuangguanx;

int MAX(int x, int y)
{
	int res;
	if(x >= y)	res = x;
	else	res = y;
	return res;
}

int MIN(int x, int y)
{
	int res;
	if(x <= y)	res = x;
	else	res = y;
	return res;
}

void main()
{
	
	FILE *fp1;
	FILE *fp2;
	int i, j, x, y, m ,n, l, num, A, B, C, D, lin, points, k;
	time_t t0, tx;
	MOUSEMSG z;	
	char name[8], t[5], scores[5];
	points = 0;
	IMAGE img[13];
	IMAGE pica[13];
	IMAGE blank;
	fp1 = fopen("txt1.txt","rb");
	for(i = 0; i < 5; i ++)
	{
		fread(&jingsu[i],sizeof(player),1,fp1);
	}
	fclose(fp1);
	
	fp2 = fopen("txt2.txt","rb");
	for(i = 0; i < 5; i ++)
	{
		fread(&chuangguan[i],sizeof(player),1,fp2);
	}
	fclose(fp2);
	
	
	loadimage(&pica[1], "pic1.jpg");
	loadimage(&pica[2], "pic2.jpg");
	loadimage(&pica[3], "pic3.jpg");
	loadimage(&pica[4], "pic4.jpg");
	loadimage(&pica[5], "pic5.jpg");
	loadimage(&pica[6], "pic6.jpg");
	loadimage(&pica[7], "pic7.jpg");
	loadimage(&pica[8], "pic8.jpg");
	loadimage(&pica[9], "pic9.jpg");
	loadimage(&pica[10], "pic10.jpg");
	loadimage(&pica[11], "pic11.jpg");
	loadimage(&pica[12], "pic12.jpg");
	loadimage(&img[1], "img1.jpg");
	loadimage(&img[2], "img2.jpg");
	loadimage(&img[3], "img3.jpg");
	loadimage(&img[4], "img4.jpg");
	loadimage(&img[5], "img5.jpg");
	loadimage(&img[6], "img6.jpg");
	loadimage(&img[7], "img7.jpg");
	loadimage(&img[8], "img8.jpg");
	loadimage(&img[9], "img9.jpg");
	loadimage(&img[10], "img10.jpg");
	loadimage(&img[11], "img11.jpg");
	loadimage(&img[12], "img12.jpg");
	loadimage(&blank, "blank.jpg");
	srand((unsigned)time(NULL));
	int a[64], b[64], pic[10][10];
	//生成一个8*8的成对图案
		
	
	initgraph(640, 480);
start:
	k = 8;
	num = 32;
	C = 0;
	D = 0;
	points = 0;
	loadimage(NULL, "background1.jpg");
	settextcolor(RED);
	settextstyle(36, 0, _T("黑体")); 
	LOGFONT f;
	gettextstyle(&f);                    
	f.lfHeight = 36;                       
	f.lfQuality = ANTIALIASED_QUALITY;    
	settextstyle(&f);                     
    while(true)
	{
		FlushMouseMsgBuffer();
		z = GetMouseMsg();
		switch(z.uMsg)
		{
			case WM_LBUTTONDOWN:
				if(z.x >= 264 && z.x <= 337 && z.y >= 217 && z.y <= 255)
				{
					C = 1;
					break;
				}
				else if(z.x >= 232 && z.x <= 384 && z.y >= 264 && z.y <= 305)
				{
					C = 2;
					break;
				}
				else if(z.x >= 215 && z.x <= 399 && z.y >= 317 && z.y <= 358)
				{
					C = 3;
					break;
				}
				else if(z.x >= 230 && z.x <= 379 && z.y >= 370 && z.y <= 410)
				{
					C = 4;
					break;
				}
		}
		if(C != 0) break;
	}

	switch(C)
	{
		case 1:
			goto here1;
		case 2:
			goto here2;
		case 3:
			goto here3;
		case 4:
			closegraph();
			return;
	}
	

	


	here1:

	loadimage(NULL, "help.jpg");
	
	while(true)
	{
		FlushMouseMsgBuffer();
		z = GetMouseMsg();
		switch(z.uMsg)
		{
			case WM_LBUTTONDOWN:
				if(z.x >= 461 && z.x <= 595 && z.y >= 367 && z.y <= 441)	goto start;
		}
	}
	
	
	/////////////////////////////////////////////////////////////////////////////////////////
	//                                                                                     //
	//主主体部分                                                                           //
	//                                                                                     //
	/////////////////////////////////////////////////////////////////////////////////////////
	here2:
	loadimage(NULL, "start.jpg");
	while(true)
	{
		FlushMouseMsgBuffer();
		z = GetMouseMsg();
		switch(z.uMsg)
		{
			case WM_LBUTTONDOWN:
				if(z.x >= 235 && z.x <= 429 && z.y >= 166 && z.y <= 214)	
				{
					D = 1;
					break;
				}
				if(z.x >= 231 && z.x <= 428 && z.y >= 251 && z.y <= 302)
				{
					D = 2;
					break;
				}
				if(z.x >= 480 && z.x <= 583 && z.y >= 397 && z.y <= 450)	goto start;
		}
		if(D != 0)	break;

	}
	here21:
	loadimage(NULL, "background4.jpg");
	for(i = 0; i < 32; i ++)
	{
		x = rand();
		a[i] = x % k + 1;
		a[i + 32] = a[i];
		b[i] = -1;
		b[i + 32] = -1;
	}
	for(i = 0; i < 64; i ++)
	{
		x = rand() % k + 2;
		j = i;
		while(1)
		{
			if(b[j] == -1) x --;
			if(x == 0)
			{
				b[j] = a[i];
				break;
			}
			j ++;
			if(j == 64) j = 0;
		}
	}
	for(j = 0; j < 10; j ++)
	{
		pic[0][j] = 0;
		pic[9][j] = 0;
	}
	for(i = 0; i < 8; i++)
	{
		pic[i + 1][0] = 0;
		pic[i + 1][9] = 0;
		for(j = 0; j < 8; j++)
		{
			pic[i+1][j+1] = b[8 * i + j];
		}
	}
	for(i = 0; i < 8; i ++)
	{
		for(j = 0; j < 8; j ++)
		{
			C = pic[i + 1][j + 1];
			putimage(i * 50 + 40, j * 50 + 40, &pica[C]);
		}
	}
	
	t0 = time(NULL);
	setbkmode(OPAQUE);
	setbkcolor(WHITE);
	setlinecolor(GREEN);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//游戏开始
	while(1)
	{
		sprintf(scores, "%d", points);       
		outtextxy(527, 224, scores);
		if(num == 0)  
		{
			if(D == 1)
				goto there;
			else
			{
				loadimage(NULL, "background3.jpg");
				k ++;
				if(k == 13)  goto there;
				num = 32;
				Sleep(2000);
				goto here21;
			}
		}

		l = 1;
		
		x = 0;
		
			while(true)
			{
		// 获取一条鼠标消息
				tx = time(NULL);
			
					switch(D)
					{
						case 1:
							sprintf(t, "%d", ( tx - t0));       
							outtextxy(523, 65, t);
							break;
						case 2:
							if(90 - tx + t0 == 9)	putimage(522,66,&blank);
							sprintf(t, "%d", ( 90 - tx + t0));       
							outtextxy(523, 65, t);
							if((90 - tx + t0) <= 0) goto there;
							break;
					}
			if(MouseHit())
				
			{
				z = GetMouseMsg();
				
			
			
			
			
				switch(z.uMsg)
				{
				
					
			
					case WM_LBUTTONDOWN:
					
			
						x = (z.x - 40) / 50 + 1;
						y = (z.y - 40) / 50 + 1;
						if(x > 8  || y > 8 )
						{
							x = 9;
							y = 9;
						}
						if(pic[x][y] == 0)  x = 0;
					
						break;
				
				}
				if(x > 0) 
				{
					putimage((x - 1) * 50 + 40, (y - 1) * 50 + 40, &img[pic[x][y]]);			
					break;
				}
				FlushMouseMsgBuffer();
			}
			}
			m = 0;
			while(true)
			{
				tx = time(NULL);
					switch(D)
					{
						case 1:
							sprintf(t, "%d", ( tx - t0));       
							outtextxy(523, 65, t);
							break;
						case 2:
							if(90 - tx + t0 == 9)	putimage(522,66,&blank);
							sprintf(t, "%d", ( 90 - tx + t0));       
							outtextxy(523, 65, t);
							if((90 - tx + t0) <= 0) goto there;
							break;
					}
				
			if(MouseHit())
				// 获取一条鼠标消息
			{
				z = GetMouseMsg();
					
				
			
				switch(z.uMsg)
				{
				
					
			
					case WM_LBUTTONDOWN:
						m = (z.x - 40) / 50 + 1;
						n = (z.y - 40) / 50 + 1;
						if(m > 8  || n > 8 )
						{
							m = 9;
							n = 9;
						}
						if(pic[m][n] == 0)  m = 0;
					
						break;
				}
				if(m > 0) 
				{
					putimage((m - 1) * 50 + 40, (n - 1) * 50 + 40, &img[pic[m][n]]);			
					break;
				}
				FlushMouseMsgBuffer();
			}
			}
		
			
		
//如果重复点击相同位置
		if(x == m && y == n) 
		{
			l = 0;
			goto here;
		}
		
//如果两个数字不相等	
		if(pic[x][y] != pic[m][n])
		{
			l = 0;
			goto here;
		}

	
//如果第一个图案第二个图案在水平位置时的判定	
		if(x == m && y != n)
		{
			if(y > n)
			{
				i = y;
				y = n;
				n = i;
			}
			if(n - y == 1)	
			{
				lin = 1;
				goto here;
			}
			for(i = y + 1; i <= n - 1; i ++)
			{
				if(pic[x][i] != 0)	
				{
					l = 0;
					break;
				}
			}
			if(l == 1)
			{
				lin = 1;
				goto here;
			}
			for(i = x + 1; i <= 9; i ++)
			{
				l = 1;
				if(pic[i][y] == 0 && pic[i][n] == 0)	
				{
					for(j = y + 1; j <= n - 1; j ++)
					{
						if(pic[i][j] != 0)	
						{
							l = 0;
							break;
						}
					}
					if(l == 1) 
					{
						lin = 2;
						goto here;
					}
				}
				else
				{
					l = 0;
					break;
				}
			}
			
			for(i = x - 1; i >= 0; i --)
			{
                l = 1;
				if(pic[i][y] == 0 && pic[i][n] == 0)	
				{
					for(j = y + 1; j <= n - 1; j ++)
					{
						if(pic[i][j] != 0)	
						{
							l = 0;
							break;
						}
					}
					if(l == 1) 
					{
						lin = 2;
						goto here;
					}
				}
				else 
				{
					l = 0;
					break;
				}
			}
			
		}


//如果第一个图案与第二个图案在竖直位置时的判定
		if(y == n && x != m)
		{
			if(x > m)
			{
				i = x;
				x = m;
				m = i;
			}
			if(m - x == 1) 
			{
				lin = 1;
				goto here;
			}
			
			for(i = x + 1; i <= m - 1; i ++)
			{
				if(pic[i][y] != 0)	
				{
					l = 0;
					break;
				}
			}
			if(l == 1)
			{
				lin = 1;
				goto here;
			}
			
			for(i = y + 1; i <= 9; i ++)
			{
				l = 1;
				if(pic[x][i] == 0 && pic[m][i] == 0)	
				{
					for(j = x + 1; j <= m - 1; j ++)
					{
						if(pic[j][i] != 0)	
						{
							l = 0;
							break;
						}
					}
					if(l == 1)
					{
						lin = 3;
						goto here;
					}
				}
				else 
				{
					l = 0;
					break;
				}
			}
			
			for(i = y - 1; i >= 0; i --)
			{
                l = 1;
				if(pic[x][i] == 0 && pic[m][i] == 0)	
				{
					for(j = x + 1; j <= m - 1; j ++)
					{
						if(pic[j][i] != 0)	
						{
							l = 0;
							break;
						}
					}
					if(l == 1) 
					{
						lin = 3;
						goto here;
					}
				}
				else 
				{
					l = 0;
					break;
				}
			}
		}

//当一个图案位于另一个图案右上角时
		if((x - m) * (y - n) > 0)
		{
			if(x > m)
			{
				i = x;
				x = m;
				m = i;
				i = y;
				y = n;
				n = i;
			}

			for(i = m - 1; i >= 0; i --)
			{
				if(pic[i][n] != 0) break;
			}
			for(j = x - 1; j >= 0; j --)
			{
				if(pic[j][y] != 0) break;
			}
			B = MAX(j + 1, i + 1);

			for(i = m + 1; i<= 9; i ++)
			{
				if(pic[i][n] != 0) break;
			}
			for(j = x + 1; j <= 9; j ++)
			{
				if(pic[j][y] != 0) break;
			}
			A = MIN(i - 1, j - 1);

			if(A < B)	l = 0;
			else
			{
				if(n - y == 1) 
				{
					l = 1;
					lin = 4;
					goto here;
				}
				
					for(i = B; i <= A;i ++)
					{
						l = 1;
						for(j = y + 1; j <= n - 1; j ++)
						{
							if(pic[i][j] != 0)
							{
								l = 0;
								break;
							}
					
						}
						if(l == 1) 
						{
							lin = 2;
							goto here;
						}
					}
			}

			for(i = n - 1; i >= 0; i --)
			{
				if(pic[m][i] != 0) break;
			}
			for(j = y - 1; j >= 0; j --)
			{
				if(pic[x][j] != 0) break;
			}
			B = max(j + 1, i + 1);

			for(i = n + 1; i<= 9; i ++)
			{
				if(pic[m][i] != 0) break;
			}
			for(j = y + 1; j <= 9; j ++)
			{
				if(pic[x][j] != 0) break;
			}
			A = min(i - 1, j - 1);
			if(B > A)	l = 0;
			else
			{
				if(m - x == 1)
				{
					l = 1;
					lin = 5;
					goto here;
				}
				for(i = B; i <= A; i ++)
				{
					l = 1;
					for(j = x + 1; j <= m - 1; j ++)
					{
						if(pic[j][i] != 0)
						{
							l = 0;
							break;
						}
					}
					if(l == 1) 
					{
						lin = 3;
						goto here;
					}
				}
			}
			goto here;
		}

//当一个图案位于另一个图案左上角时
		if((x - m) * (y - n) < 0)
		{
			if(x > m)
			{
				i = x;
				x = m;
				m = i;
				i = y;
				y = n;
				n = i;
			}

			for(i = m - 1; i >= 0; i --)
			{
				if(pic[i][n] != 0) break;
			}
			for(j = x - 1; j >= 0; j --)
			{
				if(pic[j][y] != 0) break;
			}
			B = MAX(j + 1, i + 1);

			for(i = m + 1; i<= 9; i ++)
			{
				if(pic[i][n] != 0) break;
			}
			for(j = x + 1; j <= 9; j ++)
			{
				if(pic[j][y] != 0) break;
			}
			A = MIN(i - 1, j - 1);

			if(A < B)	l = 0;
			else
			{
				if(y - n == 1) 
				{
					l = 1;
					lin = 4;
					goto here;
				}
				for(i = B; i <= A;i ++)
				{
					l = 1;
					for(j = n + 1; j <= y - 1; j ++)
					{
						if(pic[i][j] != 0)
						{
							l = 0;
							break;
						}
						
					}
					if(l == 1) 
					{
						lin = 2;
						goto here;
					}
				}
			}

			for(i = n - 1; i >= 0; i --)
			{
				if(pic[m][i] != 0) break;
			}
			for(j = y - 1; j >= 0; j --)
			{
				if(pic[x][j] != 0) break;
			}
			B = max(j + 1, i + 1);

			for(i = n + 1; i<= 9; i ++)
			{
				if(pic[m][i] != 0) break;
			}
			for(j = y + 1; j <= 9; j ++)
			{
				if(pic[x][j] != 0) break;
			}
			A = min(i - 1, j - 1);
			if(B > A)	l = 0;
			else
			{
				if(m - x == 1)
				{
					l = 1;
					lin = 5;
					goto here;
				}
				for(i = B; i <= A; i ++)
				{
					l = 1;
					for(j = x + 1; j <= m - 1; j ++)
					{
						if(pic[j][i] != 0)
						{
							l = 0;
							break;
						}
					}
					if(l == 1) 
					{
						lin = 3;
						goto here;
					}
				}
			}
			goto here;
		}

//这里有结果
		here:
		if(l == 1)	
		{
			points = points + 2;
			pic[m][n] = 0;
			pic[x][y] = 0;
			num --;
			switch(lin)
			{
				case 1:	
					line(x*50+15,y*50+15,m*50+15,n*50+15);
					break;
				case 2:
				
					line(x*50+15,y*50+15,i*50+15,y*50+15);
					line(i*50+15,y*50+15,i*50+15,n*50+15);
					line(i*50+15,n*50+15,m*50+15,n*50+15);
					break;
				
				case 3:
					line(x*50+15,y*50+15,x*50+15,i*50+15);
					line(x*50+15,i*50+15,m*50+15,i*50+15);
					line(m*50+15,i*50+15,m*50+15,n*50+15);
					break;
				
				case 4:
					
					line(x*50+15,y*50+15,(A+B)/2*50+15,y*50+15);
					line((A+B)/2*50+15,y*50+15,(A+B)/2*50+15,n*50+15);
					line((A+B)/2*50+15,n*50+15,m*50+15,n*50+15);
					break;
				
				case 5:
					line(x*50+15,y*50+15,x*50+15,(A+B)/2*50+15);
					line(x*50+15,(A+B)/2*50+15,m*50+15,(A+B)/2*50+15);
					line(m*50+15,(A+B)/2*50+15,m*50+15,n*50+15);
					break;
			}
			Sleep(200);
		}
		loadimage(NULL, "background4.jpg");
		for(i = 0; i < 8; i ++)
		{
			for(j = 0; j < 8; j ++)
			{
				C = pic[i + 1][j + 1];
				putimage(i * 50 + 40, j * 50 + 40, &pica[C]);
			}
		}
	}







here3:
	loadimage(NULL, "英雄榜.jpg");
	setbkmode(TRANSPARENT);
	gettextstyle(&f);                    
	f.lfHeight = 25;                       
	f.lfQuality = ANTIALIASED_QUALITY;    
	settextstyle(&f);
	for(i = 0;i <= 4; i ++)
	{
		outtextxy(250, 111 + i * 27, jingsu[i].mingzi);
		outtextxy(250, 278 + i * 27, chuangguan[i].mingzi);
		sprintf(scores, "%d", jingsu[i].scores);
		    
		outtextxy(465, 111 + i * 27, scores);
		sprintf(scores, "%d", chuangguan[i].scores);   
		outtextxy(465, 278 + i * 27, scores);
		outtextxy(520, 111 + i * 27, "秒");
		outtextxy(520, 278 + i * 27, "分");
	}
	while(1)
	{
		z = GetMouseMsg();
		switch(z.uMsg)
		{
			case WM_LBUTTONDOWN:
				if(z.x >= 489 && z.x <= 570 && z.y >= 424 && z.y <= 465)	goto start; 
		}
	}
//结束界面
there:;
	switch(D)
	{
		case 1:
			loadimage(NULL,"gameover.jpg");
			Sleep(1000);
			if((tx - t0) < jingsu[4].scores)	
			{
				loadimage(NULL,"hero.jpg");
				Sleep(400);
				InputBox(name,8,"请输入玩家姓名");
				strcpy(jingsu[4].mingzi,name);
				jingsu[4].scores = tx - t0;
				for(i = 4;i >= 0;i --)
				{
					if(jingsu[i].scores < jingsu[i-1].scores)
					{
						jingsux = jingsu[i-1];
						jingsu[i-1] = jingsu[i];
						jingsu[i] = jingsux;
					}
					else break;
				}
				fp1 = fopen("txt1.txt","wb");
				for(i = 0;i <= 4;i ++)
				{
					fwrite(&jingsu[i],sizeof(player),1,fp1);
				}
				fclose(fp1);
			}
			break;
	
		case 2:
			if(k == 13 && num == 0)  loadimage(NULL,"恭喜通关.jpg");
			if((tx - t0) >= 90)	loadimage(NULL,"timeout.jpg");
			Sleep(1000);
			if(points > chuangguan[4].scores)
			{
				loadimage(NULL,"hero.jpg");
				Sleep(400);
				InputBox(name,12,"请输入玩家姓名");
				strcpy(chuangguan[4].mingzi,name);
				chuangguan[4].scores = points;
				for(i = 4;i >= 0;i --)
				{
					if(chuangguan[i].scores > chuangguan[i-1].scores)
					{
						chuangguanx = chuangguan[i-1];
						chuangguan[i-1] = chuangguan[i];
						chuangguan[i] = chuangguanx;
					}
					else break;
				}
				fp2 = fopen("txt2.txt","wb");
				for(i = 0;i <= 4;i ++)
				{
					fwrite(&chuangguan[i],sizeof(player),1,fp2);
				}
				fclose(fp2);
			}
	}
	Sleep(1000);
	goto start;
}