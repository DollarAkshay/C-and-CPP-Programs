
/*memory blocks game*/

#include<stdlib.h>

#include<GL/glut.h>  // OpenGL Graphics Utility Library

#include<stdio.h>

#include<time.h>



int h=0,status_count1=0,count=0,stat=0,m=0,k=0,f=0,i=0,flg=0,flg1=1,r;

int arr[25],t[20],v[20];

int no_of_enters=0;

int match[20];

int x=0,y=0;

GLfloat cube[8][3]={ {15,15,-15},{15,15,15},{-15,15,-15},{-15,15,15},{-15,-15,-15},{-15,-15,15},{15,-15,-15},{15,-15,15}};

int x1=100,yl=-100,x2=100,y2=-60,x3=60,y3=-60,x4=60,y4=-100;

int flagx,flagy,j;

int status=1;

GLfloat theta=270.0;

char text7[]={"press x for help"};

char text6[]={"HELP"}; 

char text[]={"******************************************"};

char text3[]={"1) use arrow keys for navigation "};

char text4[]={"2) press enter to select the cube"};

char text5[]={"3) press Esc to quit"};

char text1[]={"MEMORY BLOCKS GAME"};

char text2[]={"PRESS SPACE TO START"};

char texta[]={"A MINI PROJECT ON"};

char textb[]={"Submitted by"};

char textc[]={"Under the guidance of"};

char textd[]={"Teacher name"};

char texte[]={"Your name"};

char textf[]={"Partner name"};

char textg[]={"1"};

char texth[]={"2"};

char texti[]={"name"};

char textj[]={"Department of CSE"};

char textk[]={"Lecturer"};




//char texte[]={"



void initialize()
{
 h=0,status_count1=0,count=0,stat=0,m=0,k=0,f=0,i=0,flg=0,flg1=1,r;

for(i=0;i<20;i++)
{t[i]=0;
 v[i]=0;
 match[i]=0;
}

for(i=1;i<=20;i++)
 arr[i]=0;

 no_of_enters=0;
 x=0,y=0;

 x1=100,yl=-100,x2=100,y2=-60,x3=60,y3=-60,x4=60,y4=-100;

 flagx,flagy,j;

 status=1;
}

  void randm() //to generate random numbers
   {
        int check=1;
        int n,i,j;
   	srand(time(NULL));

         for (i=1;i<=20;i++)
          {
            do
             {
		 n=rand()%20+1;
	         check=1;
		 
		 for (j=1;j<i;j++)
		 if (n == arr[j]) 
		  {
		   check=0; 
		   break; 
		  }
	      } while (!check); 
		  
                 arr[i]=n; 
		 
           }           
   }


  void selects() //to select inner pattern
   {
 

       switch(r)
       {
        case 1:glColor3f(1,1,1);glutSolidSphere(10,30,30);break;//white sphere

        case 2:glColor3f(1,1,0);glutSolidCube(10);break;//yellow cube

        case 3:glColor3f(0,0,0);glutSolidCube(10);break;//black cube

        case 4:glColor3f(1,0,1);glutSolidCube(10);break;//purple cube

        case 5:glColor3f(0,0,1);glutSolidTorus(2.0,4.0,5,5);break;//blue torus

        case 6:glColor3f(1,1,1);glutSolidSphere(10,30,30);break;//white sphere

        case 7:glColor3f(1,1,1);glutSolidCube(10);break;//white cube

        case 8:glColor3f(1,1,0);glutSolidTorus(2.0,4.0,5,5);break;//yellow torus

        case 9:glColor3f(0,0,0);glutSolidSphere(10,30,30);break;//black Sphere

        case 10:glColor3f(1,1,0);glutSolidCube(10);break;//yellow cube

        case 11:glColor3f(1,0,1);glutSolidCube(10);break;//purple cube

        case 12:glColor3f(1,1,1);glutSolidTorus(2.0,4.0,5,5);// sky blue torus

        case 13:glColor3f(0,0,1);glutSolidTorus(2.0,4.0,5,5);break;//blue torus

        case 14:glColor3f(0,1,0);glutSolidSphere(10.0,30,30);break;//green sphere

        case 15:glColor3f(0,0,0);glutSolidCube(10);break;//black cube

        case 16:glColor3f(1,1,1);glutSolidCube(10);break;//white cube

        case 17:glColor3f(1,1,0);glutSolidTorus(2.0,4.0,5,5);break;//yellow torus

        case 18:glColor3f(0,0,0);glutSolidSphere(10,30,30);break;//black Sphere

        case 19:glColor3f(0,1,0);glutSolidSphere(10.0,30,30);break;//green sphere

        case 20:glColor3f(1,1,1);glutSolidTorus(2.0,4.0,5,5);// sky blue torus
      
     }
  }      


   void calculate() //find score
     {
	  
          int score,scor[]={0,0,0,0};
	  int rem=0;
	  char score1[]={'0','0','0','0','\0'};
	  char text8[]={"YOUR SCORE IS :"};

	  score=20000/(no_of_enters);
	  j=3;
	  while(score!=0)
	  {
	    rem=score%10;
	    scor[j--]=rem;
	    score=score/10;
	  }
	   for(j=0;j<4;j++)
	   score1[j]=(scor[j]+48);
        
           glColor3f(1,0,0);
	     
           glRasterPos3f(30,0,0);
           for(j=0;text[j]!='\0';j++)
           glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[j]);

	   glRasterPos3f(30,25,0);
           for(j=0;text[j]!='\0';j++)
           glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[j]);

	   glRasterPos3f(20,10,0);
	   for(j=0;text8[j]!='\0';j++)
	   glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text8[j]);

	   for(j=0;score1[j]!='\0';j++)
	   glutBitmapCharacter(GLUT_BITMAP_9_BY_15, score1[j]);


      }    
 

   void rectangle(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4) // draw rectangle
    {
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
    }

 

  void  mycube()    //draw cube
   {
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);

	glVertex3fv(cube[1]);

	glVertex3fv(cube[0]);


	glVertex3fv(cube[6]);
	glVertex3fv(cube[7]);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[7]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[4]);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[4]);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[0]);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[2]);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[7]);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[0]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[4]);
	glEnd();
   }

  

    void  mycube1()    //draw cube
   {
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[0]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[7]);
	glEnd();

	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[7]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[4]);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[4]);
	glEnd();

	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[0]);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[2]);
	glEnd();

	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[7]);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[0]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[4]);
	glEnd();
   }
  




  void print()  // print the text
   {
	glColor3f(1,0,0);

	glRasterPos3f(90,65,0);

	for(j=0;text6[j]!='\0';j++)

	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text6[j]);

	glRasterPos3f(90,75,0);

	for(j=0;text3[j]!='\0';j++)

	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text3[j]);

	glRasterPos3f(90,85,0);

	for(j=0;text4[j]!='\0';j++)

	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text4[j]);

	glRasterPos3f(90,95,0);

	for(j=0;text5[j]!='\0';j++)

	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text5[j]);
  }
 


  void disp()     //routine to rotate cube
   {
	
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        if(h==1)
	{
 	 print();
	 h=0;
        }

	else
	{
	glColor3f(1,0,0);
 	glRasterPos3f(90,65,0);
	for(j=0;text7[j]!='\0';j++)
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text7[j]);
	}

	if((status==1||status_count1==1))
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==1) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(80,-80,0);
	r=arr[1];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-80,80,0);
	}
	}

	if((status==2||status_count1==2))
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==2) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(40,-80,0);
	r=arr[2];
	selects();
	glRotatef(theta,0,1,0);  
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-40,80,0);
	}
        }
	
	
	if((status==3||status_count1==3))
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==3) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(0,-80,0);
	r=arr[3];
	selects();
	glRotatef(theta,0.0,1.0,0.0) ;
	mycube();
	glRotatef(-theta,0.0,1.0,0.0) ;
	glTranslatef(0,80,0);
	}
	}

	if((status==4||status_count1==4))
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==4) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-40,-80,0);
	r=arr[4];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(40,80,0);
	}
	}
	
	if((status==5||status_count1==5))
	{flg=0;
	for(i=0;i<20;i++)
        if(v[i]==5) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-80,-80,0);
	r=arr[5];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(80,80,0);
	}
	}
	
	
	if((status==6||status_count1==6))
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==6) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(80,-40,0);
	r=arr[6];
	selects();
	glRotatef(theta,0,1,0);   
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-80,40,0);
	}
	}

	if((status==7||status_count1==7))
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==7) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(40,-40,0);
	r=arr[7];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-40,40,0);
	}
	}

	if((status==8||status_count1==8))
	{flg=0;
	for(i=0;i<20;i++)
        if(v[i]==8) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(0,-40,0);
	r=arr[8];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(0,40,0);
	}
	}
	
	if((status==9||status_count1==9))
	{flg=0;
	for(i=0;i<20;i++)
        if(v[i]==9) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-40,-40,0);
	r=arr[9];
	selects();
	glRotatef(theta,0,1,0); 
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(40,40,0);
	}
	}

	if(status==10||status_count1==10)
	{flg=0;
	for(i=0;i<20;i++)
        if(v[i]==10) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-80,-40,0);
	r=arr[10];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(80,40,0);
	}
	}

	if(status==11||status_count1==11)
	{flg=0;
	for(i=0;i<20;i++)
        if(v[i]==11) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(80,0,0);
	r=arr[11];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-80,0,0);
	}
	}
	
	if(status==12||status_count1==12)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==12) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(40,0,0);
	r=arr[12];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-40,0,0);
	}
	}

	if(status==13||status_count1==13)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==13) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(0,0,0);
	r=arr[13];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(0,0,0);
	}
	}


	if(status==14||status_count1==14)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==14) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-40,0,0);
	r=arr[14];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(40,0,0);
	}
	}


	if(status==15||status_count1==15)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==15) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-80,0,0);
	r=arr[15];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(80,0,0);
	}
	}


	if(status==16||status_count1==16)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==16) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(80,40,0);
	r=arr[16];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-80,-40,0);
	}
	}

	if(status==17||status_count1==17)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==17) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(40,40,0);
	r=arr[17];
	selects();
	glRotatef(theta,0,1,0);  
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(-40,-40,0);
	}
	}
	
	
	if(status==18||status_count1==18)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==18) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(0,40,0);
	r=arr[18];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(0,-40,0);
	}
	}
	if(status==19||status_count1==19)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==19) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-40,40,0);
	r=arr[19];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(40,-40,0);
	}
	}

	if(status==20||status_count1==20)
	{
	flg=0;
	for(i=0;i<20;i++)
        if(v[i]==20) 
	{
	 flg=1;
         break;
 	}
        if(flg!=1)   
	{
	glTranslatef(-80,40,0);
	r=arr[20];
	selects();
	glRotatef(theta,0,1,0);
	mycube();
	glRotatef(-theta,0,1,0);
	glTranslatef(80,-40,0);
	}
	}
	glColor3f(1.0,0.0,0.0);
	rectangle(x1,yl,x2,y2,x3,y3,x4,y4);
	glFlush();
  }




   void display(void)    //display function
    {

	
	   
	   if(k==0)
		{
			glClearColor(0.0,0.0,0.0,1.0); 
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(1.0,0.0,0.0);
	
			glRasterPos3f(23,-80,0);			

			for(j=0;texta[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, texta[j]); 
			
            
			glRasterPos3f(20,-70,0);
			for(j=0;text1[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, text1[j]); 


        	glColor3f(1.0,0.0,0.0);
			
	        
			glRasterPos3f(-40,70,0);
			for(j=0;text2[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, text2[j]); 



            glColor3f(0.0,1.0,0.0);

			glRasterPos3f(11,-50,0);
			for(j=0;textb[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textb[j]); 


             glRasterPos3f(17,-3,0);
			for(j=0;textc[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textc[j]); 

            glColor3f(0.0,0.0,1.0);
			

			
			glRasterPos3f(88,-20,0);
			for(j=0;texte[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, texte[j]); 
			
			glRasterPos3f(88,-12,0);
			for(j=0;textf[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,textf[j]); 
			
			glRasterPos3f(-68,-20,0);
			for(j=0;textg[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textg[j]); 
			
			glRasterPos3f(-68,-12,0);
			for(j=0;texth[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, texth[j]); 

			
			
			
			glRasterPos3f(88,15,0);
			for(j=0;textd[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textd[j]); 
			
			
			glRasterPos3f(-50,15,0);
			for(j=0;texti[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, texti[j]); 
			
			
			glRasterPos3f(88,20,0);
			for(j=0;textk[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textk[j]); 
			
			glRasterPos3f(-50,20,0);
			for(j=0;textk[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textk[j]); 
			
			glRasterPos3f(88,25,0);
			for(j=0;textj[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textj[j]); 
			
			glRasterPos3f(-50,25,0);
			for(j=0;textj[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textj[j]); 
				
	
			glFlush();
		}
	
		 else 
		  {
		   if(m==10)
		    {
			    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			    calculate();
			    glFlush();
		    }
		 
		  else if(f==0)
		   {
			       glClearColor(1,1,1,1);
			       glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
		 	  if(h==1)
		           {
		  	    print();
		  	    h=0;
		           }
		
			  else
		 	   {
				 glColor3f(1,0,0);
				 glRasterPos3f(90,65,0);
				 for(j=0;text7[j]!='\0';j++)
				 glutBitmapCharacter(GLUT_BITMAP_9_BY_15,text7[j]);
		  	   }

	
		if(x==1||y==1)
		match[1]=1;
		
		else if(match[1]!=1) 

		 {
			    glTranslatef(80,-80,0);
			    mycube1();
			    glTranslatef(-80,80,0);
		 }

		if(x==2||y==2)
		match[2]=2;
	 
		else if(match[2]!=2)
		    
		 {
			    glTranslatef(40,-80,0);
			    mycube1();
			    glTranslatef(-40,80,0);
		 }

		if(x==3||y==3)
		match[3]=3;

		else if(match[3]!=3)
		 {
			    glTranslatef(0,-80,0);
			    mycube1();
			    glTranslatef(0,80,0);
		 }

		if(x==4||y==4)
	  	match[4]=4;
	
	  	else if(match[4]!=4)
		 {
		 	   glTranslatef(-40,-80,0);
			   mycube1();
			   glTranslatef(40,80,0);
		 }

		if(x==5||y==5)
		match[5]=5;

		else if(match[5]!=5)
		 {
			    glTranslatef(-80,-80,0);
			    mycube1();
			    glTranslatef(80,80,0);
		 }

		if(x==6||y==6)
		match[6]=6;

		else if(match[6]!=6)
		 {
			    glTranslatef(80,-40,0);
			    mycube1();
			    glTranslatef(-80,40,0);
		 }


		if(x==7||y==7)
		match[7]=7;

		else if(match[7]!=7)
		 {

			    glTranslatef(40,-40,0);
			    mycube1();
			    glTranslatef(-40,40,0);
		 }

	
	      	if(x==8||y==8)
		match[8]=8;

		else if(match[8]!=8)
		 {
			    glTranslatef(0,-40,0);
			    mycube1();
			    glTranslatef(0,40,0);
		 }

		if(x==9||y==9)
		match[9]=9;
	
		else if(match[9]!=9)
		 {

			  glTranslatef(-40,-40,0);
			  mycube1();
			  glTranslatef(40,40,0);
		 }
	

		if(x==10||y==10)
		match[10]=10;

		else if(match[10]!=10)
		 {
			    glTranslatef(-80,-40,0);
			    mycube1();
			    glTranslatef(80,40,0);
		 }


		if(y==11||x==11)
		match[11]=11;

		else if(match[11]!=11)
		 {
			    glTranslatef(80,0,0);
			    mycube1();
			    glTranslatef(-80,0,0);
		 }

		if(x==12||y==12)
		match[12]=12;
	
	 	else if(match[12]!=12)
		 {
			    glTranslatef(40,0,0);
			    mycube1();
			    glTranslatef(-40,0,0);
		 }

		if(x==13||y==13)
		match[13]=13;

		else if(match[13]!=13)
		 {
			    glTranslatef(0,0,0);
			    mycube1();
			    glTranslatef(0,0,0);

		 }

	
		if(x==14||y==14)
		match[14]=14;

		else if(match[14]!=14)
		 {
			    glTranslatef(-40,0,0);
			    mycube1();
			    glTranslatef(40,0,0);
	 	 }

	
		if(x==15||y==15)
		match[15]=15;

		else if(match[15]!=15)
	 	 {
		   	    glTranslatef(-80,0,0);
			    mycube1();
			    glTranslatef(80,0,0);
			 }


		if(x==16||y==16)
		match[16]=16;


		else if(match[16]!=16)
		 {
			    glTranslatef(80,40,0);
			    mycube1();
			    glTranslatef(-80,-40,0);
	       
		 }

	
		if(x==17||y==17)
		match[17]=17;

		else if(match[17]!=17)
		 {
			    glTranslatef(40,40,0);
			    mycube1();
			    glTranslatef(-40,-40,0);
		 }

		if(x==18||y==18)
		match[18]=18;
	
		else if(match[18]!=18)
		 {
			    glTranslatef(0,40,0);
			    mycube1();
			    glTranslatef(0,-40,0);
		 }

	
	      	if(x==19||y==19)
		match[19]=19;
	
		else if(match[19]!=19)
		 {
			    glTranslatef(-40,40,0);
			    mycube1();
			    glTranslatef(40,-40,0);
		 }

	 
		if(x==20||y==20)
		match[0]=20;
	
		else if(match[0]!=20)
		 {
			    glTranslatef(-80,40,0);
			    mycube1();
			    glTranslatef(80,-40,0);
		 }

		glColor3f(1.0,0.0,0.0);
		rectangle(x1,yl,x2,y2,x3,y3,x4,y4);
		glFlush();

	       }
	
	       else
		{
		  disp();
		  f=0;

		
		if(match[1]!=1)
		if(status!=1 && status_count1!=1)
		  {
			glTranslatef(80,-80,0);
			mycube1();
			glTranslatef(-80,80,0);
		   }


		if(match[2]!=2)
		if(status!=2 && status_count1!=2)
		 {
			glTranslatef(40,-80,0);
			mycube1();
			glTranslatef(-40,80,0);
	 	 }


		if(match[3]!=3)
		if(status!=3 && status_count1!=3)
		 {
			glTranslatef(0,-80,0);
			mycube1();
			glTranslatef(0,80,0);
		 }


		if(match[4]!=4)
		if(status!=4 && status_count1!=4)
		 {
			glTranslatef(-40,-80,0);
			mycube1();
			glTranslatef(40,80,0);
		 }


		if(match[5]!=5)
		if(status!=5 && status_count1!=5)
		 {
			glTranslatef(-80,-80,0);
			mycube1();
			glTranslatef(80,80,0);
		 }


		if(match[6]!=6)
		if(status!=6 && status_count1!=6)
		 {
			glTranslatef(80,-40,0);
			mycube1();
			glTranslatef(-80,40,0);
		 }

	
		if(match[7]!=7)
		if(status!=7 && status_count1!=7)
		 {
			glTranslatef(40,-40,0);
			mycube1();
			glTranslatef(-40,40,0);
		 }


		if(match[8]!=8)
		if(status!=8 && status_count1!=8)
		 {
			glTranslatef(0,-40,0);
			mycube1();
			glTranslatef(0,40,0);
		  }

	
		if(match[9]!=9)
		if(status!=9 && status_count1!=9)
		 {
			glTranslatef(-40,-40,0);
			mycube1();
			glTranslatef(40,40,0);
		  }


		if(match[10]!=10)
		if(status!=10 && status_count1!=10)
		 {
			glTranslatef(-80,-40,0);
			mycube1();
			glTranslatef(80,40,0);
		 }


		if(match[11]!=11)
		if(status!=11 && status_count1!=11)
		 {

			glTranslatef(80,0,0);
			mycube1();
			glTranslatef(-80,0,0);

		 }
	

		if(match[12]!=12)
		if(status!=12 && status_count1!=12)
		 {
			glTranslatef(40,0,0);
			mycube1();
			glTranslatef(-40,0,0);
		 }

	
		if(match[13]!=13)
		if(status!=13 && status_count1!=13)
		 {
			glTranslatef(0,0,0);
			mycube1();
			glTranslatef(0,0,0);
		 }

	
		if(match[14]!=14)
		if(status!=14 && status_count1!=14)
		 {
			glTranslatef(-40,0,0);
			mycube1();
			glTranslatef(40,0,0);
		 }
	
	
		if(match[15]!=15)
		if(status!=15 && status_count1!=15)
		 {
			glTranslatef(-80,0,0);
			mycube1();
			glTranslatef(80,0,0);
		 }

	
		if(match[16]!=16)
		if(status!=16 && status_count1!=16)
		 {
			glTranslatef(80,40,0);
			mycube1();
			glTranslatef(-80,-40,0);
		 }
	

		if(match[17]!=17)
		if(status!=17 && status_count1!=17)
		 {
			glTranslatef(40,40,0);
			mycube1();
			glTranslatef(-40,-40,0);
		 }


		if(match[18]!=18)
		if(status!=18 && status_count1!=18)
		 {
		 	glTranslatef(0,40,0);
			mycube1();
			glTranslatef(0,-40,0);
		 }

	
	 	if(match[19]!=19)
		if(status!=19 && status_count1!=19)
		 {
			glTranslatef(-40,40,0);
			mycube1();
			glTranslatef(40,-40,0);
		 }

	
		if(match[0]!=20)
		if(status!=20 && status_count1!=20)
	       	 {
			glTranslatef(-80,40,0);
			mycube1();
			glTranslatef(80,-40,0);
		 }

		


	        if(m<20)
		{ 
		if(stat>0)
		{
	        if(t[0]==0) 
		if((arr[status]==1 && arr[status_count1] ==6) ||(arr[status_count1]==1&& arr[status]==6))
		{    
		x=status;
		y=status_count1;m++;t[0]=1;v[0]=x;v[1]=y;
		}
	

                if(t[1]==0) 
		if((arr[status]==2 && arr[status_count1]==10)  || (arr[status_count1]==2 && arr[status]==10))
		{
		x=status;t[1]=1;
		y=status_count1;m++;v[2]=x;v[3]=y;
		}

                if(t[2]==0)
		if((arr[status]==3 && arr[status_count1]==15) || (arr[status_count1]==3 && arr[status]==15))
		{
		x=status;t[2]=1;
		y=status_count1;m++;v[4]=x;v[5]=y;
		}

                if(t[3]==0) 
		if((arr[status]==4 && arr[status_count1]==11) || (arr[status_count1]==4 && arr[status]==11))
		{
		x=status;t[3]=1;
		y=status_count1;m++;v[6]=x;v[7]=y;
		}
                
                if(t[4]==0)    
		if((arr[status]==5 && arr[status_count1]==13) || (arr[status_count1]==5 && arr[status]==13))
		{
		x=status;t[4]=1;
		y=status_count1;m++;v[8]=x;v[9]=y;
		}
               

                if(t[5]==0) 
		if((arr[status]==7 && arr[status_count1]==16) || (arr[status_count1]==7 && arr[status]==16))
		{
		x=status;t[5]=1;
		y=status_count1;m++;v[10]=x;v[11]=y;
		}

                
                if(t[6]==0)  
		if((arr[status]==8 && arr[status_count1]==17) || (arr[status]==17 && arr[status_count1]==8))
		{
		x=status;t[6]=1;
		y=status_count1;m++;v[12]=x;v[13]=y;
		}

		if(t[7]==0)
		if((arr[status]==9 && arr[status_count1]==18) || (arr[status_count1]==9 && arr[status]==18))
		{
		x=status;t[7]=1;
		y=status_count1;m++;v[14]=x;v[15]=y;
		}

		
		if(t[8]==0)
		if((arr[status]==12 && arr[status_count1]==20) || (arr[status_count1]==12 && arr[status]==20))
		{
		x=status;t[8]=1;
		y=status_count1;m++;v[16]=x;v[17]=y;
		}


		if(t[9]==0)
		if((arr[status]==14 && arr[status_count1]==19) || (arr[status_count1]==14 && arr[status]==19))
		{
		x=status;t[9]=1;
		y=status_count1;m++;v[18]=x;v[19]=y;
		}
	     
		}
		}	     

	      }
	
	    }
	       glFlush();
	   }



	   void mykey(unsigned char key,int x,int y) //function to handle "normal" key presses
	     {
	      
	     switch(key)
	      {

	        case 32:   k=1;
			   glutPostRedisplay();

	 	           break;

		case 27:  exit(0);

		case 13:  
			    f=1;

			    if(m!=10)
			    no_of_enters++;
			    
			    if(count==0)
			     { 
				count++;
				status_count1=status;
				stat=1;
			     }
				
				else if(count==1)
				count++;	
			       
			    glutPostRedisplay();
				 
		           break;

		case 'x': h=1;
			  glutPostRedisplay();
			  
			   break;
	       case 'y':glRotatef(3,1,1,0);glutPostRedisplay();break;

               case 'r':if(m==10){initialize();randm();glutPostRedisplay();}break;
	       }
	    }


   void myspecial(int key,int x,int y)  //function to handle "special" key presses
    {

      switch(key)
       {

 	case GLUT_KEY_UP:if(status>5)
                          {
		              status-=5;
		              glColor3f(1.0,0.0,0.0);
		              yl=yl-40;y2=y2-40;y3=y3-40;y4=y4-40;
		              rectangle(x1,yl,x2,y2,x3,y3,x4,y4);
			      if(count==2) count=0,f=0,status_count1=status;
		              glutPostRedisplay();
                          }
                            break;


	case GLUT_KEY_DOWN:if(status<16)
                            {
		               status+=5;
		               glColor3f(1.0,0.0,0.0);
		               yl=yl+40;y2=y2+40;y3=y3+40;y4=y4+40;
		               rectangle(x1,yl,x2,y2,x3,y3,x4,y4);
			       if(count==2)count=0,f=0,status_count1=status;
		               glutPostRedisplay();
                            }
                               break;

 
 	case GLUT_KEY_LEFT:if(status!=1&&status!=6&&status!=11&&status!=16)
                            {
		                status--;
		                glColor3f(1.0,0.0,0.0);
		                x1=x1+40;x2=x2+40;x3=x3+40;x4=x4+40;
			        rectangle(x1,yl,x2,y2,x3,y3,x4,y4);
				if(count==2)count=0,f=0,status_count1=status;
		                glutPostRedisplay();
                            }
                               break;


  
 	case GLUT_KEY_RIGHT:if(status!=5&&status!=10&&status!=15&&status!=20)
                             {
		                  status++;
		                  glColor3f(1.0,0.0,0.0);
		                  x1=x1-40;x2=x2-40;x3=x3-40;x4=x4-40;
		                  rectangle(x1,yl,x2,y2,x3,y3,x4,y4);
				  if(count==2)count=0,f=0,status_count1=status;
		                  glutPostRedisplay();
		              }
                         	 break;
      }
   }



   void init()  // initialize openGL
    {

	randm();

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(100.0,-100.0,100.0,-100.0,100.0,-100.0);

	glMatrixMode(GL_MODELVIEW);

	glClearColor(1.0,1.0,1.0,1.0);

	glLineWidth(4);
    }


   int main(int argc,char **argv)  //main routine
    {
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(1000,1000);
 
	glutCreateWindow("GAME");

	glutDisplayFunc(display);

	glutKeyboardFunc(mykey);

	glutSpecialFunc(myspecial);

	init();
	 
	glEnable(GL_DEPTH_TEST) ;

	glutMainLoop();
    }


