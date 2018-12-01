//assumptions- total 20 grounds ,each ground can have maximum 5 sports,booking allowed for 1 month.
/*struct date
{
	int day;
	int month;
	int year;
}; */
struct games
{
	char gameName[20];
	char d[9]; //one date in format of yyyymmdd ;
	int stTime;
	int endTime;
	int rate;
};
struct bookGames
{
	char sportsName[20];
	char bdate[9] /*yyyymmdd format of date*/;
	int start;
	int end;
};

struct ground
{
	char groundName[20];
	char cityName[20];
	char stateName[20];
	struct games sports[5];
	struct bookGames bg[150];
	int j;
}g[20];

#include<stdio.h>
#include<string.h>
void intialise();
void getGroundInfo();
void addSport();
void deleteSport();
void addGround();
void deleteGround();
void updateGround();
void getFixturesInCity();
void getFixturesInState();
void uniqueGames();
void sportWithGround();
void findLocationsForGame();
void findLocationsForGameInTimeRange();
void getFixturesInState();
void getFixturesSortedOnDate();
void getFixturesSortedOnDate();
void getFixturesSortedOnState();
void isAvailable();
void FindLocationsForGameEvents();
void ClashOfMatches();
void GiveListOfGroundsHavingMinOneMatch();
void GiveListOfGroundsHavingAtleastKMatches();
void SortOnPriceForAGame();
void FindGamesSchedule();
void enterValuesIntoDatabase();
int main()
{
	int choice;
	intialise();
    enterValuesIntoDatabase();
	printf("please select a choice \n");
	printf("1. to get info about ground \n");
	printf("2. to add a sports to ground \n");
	printf("3. to delete a sport \n");
	printf("4. to add a ground in city \n");
	printf("5. to delete a ground in city \n");
	printf("6. to update info about ground \n");
	printf("7. to get fixtures in city \n");
	printf("8. to get fixtures in state \n");
	printf("9. to get fixtures sorted on date \n");
	printf("10. to get fixtures sorted on state \n");
	printf("11. to get list of ground available on given date and time \n");
	printf("12. to get unique games played on that ground \n");
	printf("13. to get names of ground in which particular sports is played \n");
	printf("14. to get loctions of ground where a particular event is scheduled \n");	
	printf("15. to find locations for game to be played \n");
	printf("16. to find locations of game in given time range \n");
	printf("17. to get details about clashing matches \n");
	printf("18. to get list of grounds having minimum one match \n");
	printf("19. to get list of grounds having minimum k match \n");
    printf("20. to get sort on price for game \n");
    printf("21. to get games shedule \n");

	
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		getGroundInfo();
		break;
	case 2:
		addSport();
		break;
	case 3:
		deleteSport();
		break;
	case 4:
		addGround();
		break;
	case 5:
		deleteGround();
		break;
	case 6:
		updateGround();
		break;
	case 7:
	    getFixturesInCity();
		break;	
	case 8:
		getFixturesInState();
		break;	
	case 9:
	     getFixturesSortedOnDate();
	     break;
	case 10:
	     getFixturesSortedOnState();  
		 break;
	case 11:
	     isAvailable();  
		 break;
	case 12:
		uniqueGames();
		break;
	case 13:
		sportWithGround();
		break;
	case 14:
	     FindLocationsForGameEvents();
		 break;	
	case 15:
		findLocationsForGame();
		break;
	case 16:	
	    findLocationsForGameInTimeRange();
		break;
	case 17:
		ClashOfMatches();
	    break;
	 case 18:
	 	 GiveListOfGroundsHavingMinOneMatch();
	     break;
	 case 19:
	      GiveListOfGroundsHavingAtleastKMatches();
		  break;    
	   case 20:
	   SortOnPriceForAGame();  
	   break; 
	   case 21:
	    FindGamesSchedule(); 
	    break;
	default: printf("incorrect choice selected");
			 break;
	}
	
	return 0;
}
void intialise()
{
	int i,j,k,l;
	for(i=0;i<20;i++)
	{
		g[i].groundName[0]='\0';
		g[i].cityName[0]='\0';
		g[i].stateName[0]='\0';
		g[i].j=0;
		for(j=0;j<5;j++)
		{
		
			g[i].sports[j].gameName[0]='\0';
		//	for(l=0;l<9;l++)
		//	{
		//		g[i].sports[j].d[l].day=0;
		//		g[i].sports[j].d[l].month=0;
		//		g[i].sports[j].d[l].year=0;
				
		  //  }
		  g[i].sports[j].d[0]='\0';
		    g[i].sports[j].stTime=0;
			g[i].sports[j].endTime=0;
			g[i].sports[j].rate=0;
	   }
	   for(k=0;k<150;k++)
	   {
	   
			g[i].bg[k].sportsName[0]='\0';
			g[i].bg[k].bdate[0]='\0';
			g[i].bg[k].start=0;
			g[i].bg[k].end=0;
	   }
	}
}
void getGroundInfo()
{
	char city[20];
	int j,k;
	char temp[20];
   	/*strcpy(g[2].cityName,"abcd");
   	strcpy(g[3].cityName,"abcd");
    strcpy(g[2].groundName,"msd"); 
    strcpy(g[3].groundName,"masd"); 
	strcpy(g[3].sports[0].gameName,"cricket");
	strcpy(g[3].sports[1].gameName,"basketball"); */
	printf("enter city ");
	scanf("%s",&city);
	int i;
	struct ground t;
	for(i=0;i<20;i++)
	{
		for(j=1;j<20-i;j++)
		{
		
			if(strcmp(g[j].groundName,g[j-1].groundName)<0)
			{
				t=g[j];
				g[j]=g[j-1];
				g[j-1]=t;
			}
	
	    }
	}
	
	for(i=0;i<20;i++)
	{
		if(g[i].groundName[0]!='\0')
		{
			for(j=0;j<5;j++)
			{
				for(k=1;k<5-j;k++)
				{
					if(strcmp(g[i].sports[j].gameName,g[i].sports[j-1].gameName)<0)
					{
						strcpy(temp,g[i].sports[j].gameName);
						strcpy(g[i].sports[j].gameName,g[i].sports[j-1].gameName);
						strcpy(g[i].sports[j-1].gameName,temp);
						
						
					}
				}
			}
		}
 	}   
	for(i=0;i<20;i++)
	{
		if(strcmp(g[i].cityName,city)==0)
		{
			printf(" %s \t ",g[i].groundName);
			for(k=0;k<5;k++)
			{
				printf("%s \t",g[i].sports[k].gameName);
			}
		}
    }
}
void addSport()
{
	int i,flag=0,k;
	char grndname[20],ctyname[20],sprtname[20],rt,dt[9];
	printf("enter  ground name");
	scanf("%s",&grndname);
	printf("enter  city name");
	scanf("%s",&ctyname);
	printf("enter  sports name");
	scanf("%s",&sprtname);
	printf("rate of sport");
	scanf("%d",&rt);
	printf("enter date of availabilty in format yyyymmdd");
	scanf("%s",&dt);
	
//	strcpy(g[2].cityName,"abcd");
  //  strcpy(g[2].groundName,"msd");
	for(i=0;i<20  && flag==0;i++)
	{
		if(strcmp(g[i].groundName,grndname)==0)
		{
			if(strcmp(g[i].cityName,ctyname)==0)
			{
				for(k=0;k<5 && flag==0;k++)
				{
					if(g[i].sports[k].gameName[0]=='\0')
					{
					
						strcpy(g[i].sports[k].gameName,sprtname);
						g[i].sports[k].rate=rt;
						strcpy(g[i].sports[k].d,dt);
						(g[i].j)++;
						flag=1;
					}
				}
			}
		}	
	}
/*	i--;
	k--;
	printf("%s",g[i].sports[k].gameName); */
	if(flag==1) printf("SUCCESS");
	else printf("FAILURE");
}
void deleteSport()
{
	int i,flag=0,k;
	char grndname[20],ctyname[20],sprtname[20];
	printf("enter  ground name");
	scanf("%s",&grndname);
	printf("enter  city name");
	scanf("%s",&ctyname);
	printf("enter  sports name");
	scanf("%s",&sprtname);
/*	strcpy(g[2].cityName,"abcd");
	strcpy(g[2].sports[3].gameName,"basket");
    strcpy(g[2].groundName,"msd"); */
	for(i=0;i<20  && flag==0;i++)
	{
		if(strcmp(g[i].groundName,grndname)==0)
		{
			if(strcmp(g[i].cityName,ctyname)==0)
			{
				for(k=0;k<5;k++)
				{
				
					if(strcmp(g[i].sports[k].gameName,sprtname)==0)
					{
				     	
						g[i].sports[k].gameName[0]='\0';
							//	g[i].sports[k].d[0].month=0;
					//	g[i].sports[k].d[0].year=0;
						g[i].sports[k].d[0]='\0';
				
						g[i].sports[k].stTime=0;
						g[i].sports[k].endTime=0;
						g[i].sports[k].rate=0;
						flag=1;
					}
				}
				
			}
		}	
	}
	//i--;
	//printf("%s",g[i].sports[--(g[i].j)].gameName);
	if(flag==1) printf("SUCCESS");
	else printf("FAILURE");

}
void addGround()
{	int flag=0;
	char ingroundname[20],incityname[20],instatename[20];
	printf("enter  ground name");
	scanf("%s",&ingroundname);
	printf("enter  city name");
	scanf("%s",&incityname);
	printf("enter  state name");
	scanf("%s",&instatename);
	int i;
	for(i=0;i<20 &&flag==0;i++)
	{
		if(g[i].groundName[0]!='\0')
		{
			strcpy(g[i].groundName,ingroundname);
			flag=1;
		}
	}
		if(flag==1) printf("SUCCESS");
	else printf("FAILURE");
	
}
void deleteGround()
{	int flag=0,i,j,k,l;
	char ingroundname[20],incityname[20];
	printf("enter  ground name");
	scanf("%s",&ingroundname);
	printf("enter  city name");
	scanf("%s",&incityname);

	for(i=0;i<20 &&flag==0;i++)
	{
		if(strcmp(g[i].cityName,incityname)==0)
		{
			
		
			if(strcmp(g[i].groundName,ingroundname)==0)
			{
				g[i].groundName[0]='\0';
				g[i].cityName[0]='\0';
				g[i].stateName[0]='\0';
				g[i].j=0;
				for(j=0;j<5;j++)
				{	
			
					g[i].sports[j].gameName[0]='\0';
				/*	for(l=0;l<9;l++)
					{
						g[i].sports[j].d[l].day=0;
						g[i].sports[j].d[l].month=0;
						g[i].sports[j].d[l].year=0;
					
				    } */
				    g[i].sports[j].d[0]='\0';
				    g[i].sports[j].stTime=0;
					g[i].sports[j].endTime=0;
					g[i].sports[j].rate=0;
		  		 }
		   			for(k=0;k<150;k++)
		  			 {
		   	
						g[i].bg[k].sportsName[0]='\0';
						g[i].bg[k].bdate[0]='\0';
						g[i].bg[k].start=0;
						g[i].bg[k].end=0;
						flag=1;
					}
			}	
		}
	}
		if(flag==1) printf("SUCCESS");
		else printf("FAILURE");
	
} 
void updateGround() //updated things will be overwritten.(will not be appended)
{	int flag=0,i,j;
	char ingroundname[20],incityname[20];
	int st,et;
	char date[9];
	/*strcpy(g[2].cityName,"abcd");
	strcpy(g[2].sports[3].gameName,"basket");
    strcpy(g[2].groundName,"msd"); */
	printf("enter  ground name");
	scanf("%s",&ingroundname);
	printf("enter  city name");
	scanf("%s",&incityname);
	printf("enter new record \n");
	printf("game name , hourly rate,date in yyyymmdd,start time end time");
	char gn[20];
	int rate;
	scanf("%s",&gn);
	scanf("%d",&rate);
	scanf("%s",date);
	scanf("%d",&st);
    scanf("%d",&et);
	for(i=0;i<20 &&flag==0;i++)
	{
		if(strcmp(g[i].cityName,incityname)==0)
		{
			
		
			if(strcmp(g[i].groundName,ingroundname)==0)
			{
				strcpy(g[i].sports[0].gameName,gn);
				g[i].sports[0].rate=rate;
				strcpy(g[i].sports[0].d,date);
				
						g[i].sports[0].stTime=st;
						g[i].sports[0].endTime=et;
				flag=1;		
					
			}	
		}
	}
	/*i--;
	printf("%s",g[i].sports[0].gameName); */
		if(flag==1) printf("SUCCESS");
		else printf("FAILURE");
	
}
void uniqueGames() 
{
	struct ground t;
	int i,j,k,flag;
	char incityname[20],ingroundname[20];
/*	strcpy(g[2].cityName,"abcd");
   	strcpy(g[3].cityName,"abcd");
    strcpy(g[2].groundName,"msd"); 
    strcpy(g[3].groundName,"masd"); 
	strcpy(g[2].sports[3].gameName,"cricket");
	strcpy(g[2].sports[1].gameName,"basketball");
	strcpy(g[3].sports[3].gameName,"basketball");
	strcpy(g[3].sports[2].gameName,"volleyball");
	strcpy(g[3].sports[1].gameName,"baseball"); */
	int pos=0,len=0,posgrnd=0;
	for(i=0;i<20;i++)
	{
		for(j=1;j<20-i;j++)
		{
		
			if(strcmp(g[j].cityName,g[j-1].cityName)<0)
			{
				t=g[j];
				g[j]=g[j-1];
				g[j-1]=t;
			}
	
	    }
	}
	printf("enter city name");
	scanf("%s",&incityname);
	printf("enter ground name");
	scanf("%s",&ingroundname);
	for(i=0;i<20;i++)
	{
		if(strcmp(g[i].cityName,incityname)==0)
		{
			pos=i;
			len++;
			if(strcmp(g[i].groundName,ingroundname)==0) posgrnd=i;
		}
	}
	for(i=0;i<5;i++)
	{
		flag=0;
		for(j=(pos-len+1);j<(pos+1) && flag==0;j++)
		{
			if(j!=posgrnd)
			{
			
				for(k=0;k<5 && flag==0;k++)
				{
					if(strcmp(g[posgrnd].sports[i].gameName,g[j].sports[k].gameName)==0)
					{
					  flag=1;
				    }
				}
			}
		}
		if(flag==0) printf("%s \n",g[posgrnd].sports[i].gameName);
		
	}
	
}
void sportWithGround() 
{
	struct ground t;
	int i,j,flag;
	/*strcpy(g[2].cityName,"abcd");
   	strcpy(g[3].cityName,"abcd");
    strcpy(g[2].groundName,"msd"); 
    strcpy(g[3].groundName,"masd"); 
	strcpy(g[2].sports[3].gameName,"cricket");
	strcpy(g[2].sports[1].gameName,"basketball");
	strcpy(g[3].sports[3].gameName,"basketball");
	strcpy(g[3].sports[2].gameName,"volleyball");
	strcpy(g[3].sports[1].gameName,"baseball");*/
	for(i=0;i<20;i++)
	{
		for(j=1;j<20-i;j++)
		{
		
			if(strcmp(g[j].groundName,g[j-1].groundName)<0)
			{
				t=g[j];
				g[j]=g[j-1];
				g[j-1]=t;
			}
	
	    }
	}
	printf("enter game name");
	char ingamename[20];
	scanf("%s",&ingamename);
	for(i=0;i<20;i++)
	{
		flag=0;
		for(j=0;j<5 && flag==0;j++)
		{
			if(strcmp(g[i].sports[j].gameName,ingamename)==0) flag=1;
		}
		if(flag==1) printf("%s \n",g[i].groundName);
	}
	
}
void findLocationsForGame()
{
	char gname[20];
	char sd[9];
	int st,flag,found,i,j,k;
	
/*	strcpy(g[2].cityName,"abcd");
   	strcpy(g[3].cityName,"abcd");
    strcpy(g[2].groundName,"msd"); 
    strcpy(g[3].groundName,"masd"); 
	strcpy(g[2].sports[3].gameName,"cricket");
	strcpy(g[2].sports[1].gameName,"basketball");
	strcpy(g[3].sports[3].gameName,"basketball");
	strcpy(g[3].sports[2].gameName,"volleyball");
	strcpy(g[3].sports[1].gameName,"baseball");
	strcpy(g[2].bg[0].sportsName,"cricket");
	strcpy(g[2].bg[1].sportsName,"cricket");
	strcpy(g[2].bg[3].sportsName,"basketball");
	strcpy(g[2].bg[0].bdate,"20181028");
	strcpy(g[2].bg[1].bdate,"20181025");
	strcpy(g[2].bg[3].bdate,"20181028");
	strcpy(g[3].bg[0].sportsName,"baseball");
	strcpy(g[3].bg[0].bdate,"20181028");
	g[2].bg[0].start=11;
	g[2].bg[0].end=13;
	g[2].bg[1].start=1;
	g[2].bg[1].end=5;
	g[3].bg[0].start=11;
	g[3].bg[0].end=14; */
	
	printf("enter game name");
	scanf("%s",&gname);
	printf("enter date in yyyymmdd format");
	scanf("%s",&sd);
	printf("enter start time in military hours");
	scanf("%d",&st);
	
	for(i=0;i<20;i++)
	{
		flag=0;
		found=0;
		for(k=0;k<5;k++)
		{
			if(strcmp(g[i].sports[k].gameName,gname)==0) flag=1;
		}
		
		for(j=0;j<150 && g[i].bg[j].sportsName!='\0' && flag==1;j++)
		{
				if(strcmp(g[i].bg[j].sportsName,gname)==0)
				{
					if(strcmp(g[i].bg[j].bdate,sd)==0)
					{
						if(st<g[i].bg[j].end && st>g[i].bg[j].start)
						{
							found=1;
						}
					}	
				}
		}
		if(flag==1 && found==0)
		{
			printf("%s \n",g[i].groundName);
			printf("%s",g[i].cityName);
		}
	}
}
void findLocationsForGameInTimeRange()
{
	char gname[20];
	char sd[9];
	int st,et,i,j,k;
	int flag,found,duration;
	printf("enter game name");
	scanf("%s",&gname);
	printf("enter date in format yyyymmdd");
	scanf("%s",&sd);
	printf("enter start time");
	scanf("%d",&st);
	printf("enter end time");
	scanf("%d",&et);
	printf("enter time duration for sports");
	scanf("%d",&duration);
	int strt,a;
	strt=st;
	/*	strcpy(g[2].cityName,"abcd");
   	strcpy(g[3].cityName,"abcd");
    strcpy(g[2].groundName,"msd"); 
    strcpy(g[3].groundName,"masd"); 
	strcpy(g[2].sports[3].gameName,"cricket");
	strcpy(g[2].sports[1].gameName,"basketball");
	strcpy(g[3].sports[3].gameName,"basketball");
	strcpy(g[3].sports[2].gameName,"volleyball");
	strcpy(g[3].sports[1].gameName,"baseball");
	strcpy(g[2].bg[0].sportsName,"cricket");
	strcpy(g[2].bg[1].sportsName,"cricket");
	strcpy(g[2].bg[3].sportsName,"basketball");
	strcpy(g[2].bg[0].bdate,"20181028");
	strcpy(g[2].bg[1].bdate,"20181025");
	strcpy(g[2].bg[3].bdate,"20181028");
	strcpy(g[3].bg[0].sportsName,"baseball");
	strcpy(g[3].bg[0].bdate,"20181028");
	g[2].bg[0].start=11;
	g[2].bg[0].end=13;
	g[2].bg[1].start=1;
	g[2].bg[1].end=5;
	g[3].bg[0].start=11;
	g[3].bg[0].end=14;
	g[2].bg[3].start=12;
	g[2].bg[3].end=15;
	*/
		for(i=0;i<20;i++)
	{
		flag=0;
		for(k=0;k<5;k++)
		{
			if(strcmp(g[i].sports[k].gameName,gname)==0) flag=1;
		}
		found=1;
		a=0;
		for(j=0;j<150 && g[i].bg[j].sportsName!='\0' && flag==1 && found==1;j++)
		{
		    a=1;
				if(strcmp(g[i].bg[j].sportsName,gname)==0)
				{   a=2;
					found=1;
					if(strcmp(sd,g[i].bg[j].bdate)==0)
					{
					    a=3;	
						while((strt+duration)<et && found==1)//20 means 20:00 in military time
						{
							if((strt+duration)<=g[i].bg[j].start)	found=0;
							else strt++;
						}
					}
				}
				
		}
		
		if(flag==1 && (found==0 || a!=3))
		{
				printf("%s \n",g[i].groundName);
			printf("%s \n",g[i].cityName);
			
		}
	}
}
void getFixturesInCity(){

int i,j,k;

char cityname[20];
printf("CITYNAME:");
scanf("%s",cityname);

char date1[9],date2[9];
printf("ENTER STARTING AND ENDING DATES :");
scanf("%s%s",date1,date2);

//TEMPORARY ARRAY FOR SORTING

struct tempForSorting{
  char groundName[20];
  char sportsName[20];
//TEMPORARY ARRAY FOR SORTING

}tfs[150];

int rec=0;

//MOVE THE REQUIRED ENTITIES FROM DATABASE INTO TEMPORARY STRUCTURE FOR EASE OF SORTING
for(i=0;i<20;i++)
{
    if(strcmp(g[i].cityName,cityname)==0)
  {
      for(j=0;j<150;j++)
    {
      if(strcmp(g[i].bg[j].bdate,date1)>=0 && strcmp(g[i].bg[j].bdate,date2)<=0 )
      {
        strcpy(tfs[rec].groundName,g[i].groundName);
        strcpy(tfs[rec].sportsName,g[i].bg[j].sportsName);
        rec++;
      }
    }
  }
}

    struct tempForSorting temp;
    //SORT ACCORDING TO GORUNDNAME
    for(i=0;i<rec;i++)
    {
      for(j=0;j<rec-i-1;j++)
      {
          if(strcmp(tfs[j].groundName,tfs[j+1].groundName)>0)
          {
            temp=tfs[j];
            tfs[j]=tfs[j+1];
            tfs[j+1]=temp;
          }
      }
    }
    //SORT ACCORDNG TO SPORTSNAME
    for(i=0;i<rec;i++)
    {
      for(j=0;j<rec-i-1;j++)
      {
          if(strcmp(tfs[j].sportsName,tfs[j+1].sportsName)>0)
          {
            temp=tfs[j];
            tfs[j]=tfs[j+1];
            tfs[j+1]=temp;
          }
      }
    }

    printf("THE LIST OF SPORTS IS :");
    for(i=0;i<rec;i++)
    {
      printf("\t%s\n",tfs[i].sportsName) ;
    }

  }
  void getFixturesInState(){

int i,j,k;


char statename[20];
printf("STATENAME:");
scanf("%s",statename);

/*char date[20];
printf("DATE:");
scanf("%s",date);*/

struct tempForSorting{
  char groundName[20];
  char sportsName[20];
  char cityName[20];
}tfs[150];

int rec=0;

//MOVE THE REQUIRED ENTITIES FROM DATABASE INTO TEMPORARY STRUCTURE FOR EASE OF SORTING
for(i=0;i<20;i++)
{
    if(strcmp(g[i].stateName,statename)==0)
  {
      for(j=0;j<150;j++)
    {
      /*if(strcmp(g[i].bg[j].bdate,date)==0)*/
      {
        strcpy(tfs[rec].groundName,g[i].groundName);
        strcpy(tfs[rec].sportsName,g[i].bg[j].sportsName);
        strcpy(tfs[rec].cityName,g[i].cityName);
        rec++;
      }
    }
  }
}

    struct tempForSorting temp;

    //SORT ACCORDING TO GROUNDNAME
    for(i=0;i<rec;i++)
    {
      for(j=0;j<rec-i-1;j++)
      {
          if(strcmp(tfs[j].groundName,tfs[j+1].groundName)>0)
          {
            temp=tfs[j];
            tfs[j]=tfs[j+1];
            tfs[j+1]=temp;
          }
      }
    }

    //SORT ACCORDING TO SPORTSNAME
    for(i=0;i<rec;i++)
    {
      for(j=0;j<rec-i-1;j++)
      {
          if(strcmp(tfs[j].sportsName,tfs[j+1].sportsName)>0)
          {
            temp=tfs[j];
            tfs[j]=tfs[j+1];
            tfs[j+1]=temp;
          }
      }
    }

    //SORT ACCORDING TO CITYNAME
        for(i=0;i<rec;i++)
        {
          for(j=0;j<rec-i-1;j++)
          {
              if(strcmp(tfs[j].cityName,tfs[j+1].cityName)>0)
              {
                temp=tfs[j];
                tfs[j]=tfs[j+1];
                tfs[j+1]=temp;
              }
          }
        }


        printf("THE LIST OF SPORTS ARE :") ;
    for(i=0;i<rec;i++)
    {
      printf("\t%s\n",tfs[i].sportsName) ;
    }

  }
  void getFixturesSortedOnDate()
{
  int i,j,k;
  //MAKE A TEMPORARY DATABASE FOR TAKING REQUIRED DATA FROM THE ORIGINAL DATABASE
  struct sortedGrounds{
    char ground[20];
    char ssp[20];//unsorted sports
    //date 0
    char date[9];
    //time
    int stTime;
    int endTime;
  }s[200];

  int rec=0;

  struct sortedGrounds tempForSortedGrounds;


  	for(j=0;j<20;j++)
  	{
      for(k=0;k<5;k++)
      {
         strcpy(s[rec].ground,g[j].groundName);
  	     strcpy(s[rec].ssp,g[j].sports[k].gameName);
         strcpy(s[rec].date,g[j].sports[k].d);
         s[rec].stTime=g[j].sports[k].stTime;
         s[rec].endTime=g[j].sports[k].endTime;
         rec++;
      }
	  }

    //FOR SORTING ACCORDING TO NEXT AVAILABLE DATE
  for(i=0;i<100;i++)
  {
  	for(j=i;j<100-i-1;j++)
  	{
  		  if(strcmp(s[j].date,s[j+1].date)>0)
        {
          tempForSortedGrounds=s[j];
          s[j]=s[j+1];
          s[j+1]=tempForSortedGrounds;
        }

	  }
  }

    //FOR SORTING ACCORDING TO STARTING TIME
  for(i=0;i<100;i++)
  {
    for(j=0;j<100-i-1;j++)
    {
      if(s[j].stTime>s[j+1].stTime)
      {
        tempForSortedGrounds=s[j];
        s[j]=s[j+1];
        s[j+1]=tempForSortedGrounds;
      }
    }
  }



	printf("LIST OF GROUNDS SORTED ACCORDING TO DATE AND TIME :");

	for(i=0;i<100;i++)
	{
		printf("\t%s\n",s[i].ground) ;
	}

}
void getFixturesSortedOnState()
{
  int i,j,k;

  struct ground temp;
  //SORT ACCORDING TO STATE
  for(i=0;i<20;i++)
  {
  	for(j=i;j<20-i-1;j++)
  	{
  		if(strcmp(g[j].stateName,g[j+1].stateName)>0)
  		{
	   		temp=g[j];
	   		g[j]=g[j+1];
	   		g[j+1]=temp;
	    }
	}
  }
//SORT ACCORDING TO CITY
  for(i=0;i<20;i++)
  {
  	for(j=i;j<20-i-1;j++)
  	{
  		if(strcmp(g[j].stateName,g[j+1].stateName)==0)
  		{
		  	if(strcmp(g[j].cityName,g[j+1].cityName)>0)
  			{
	   			temp=g[j];
	   			g[j]=g[j+1];
	   			g[j+1]=temp;
	    	}
		  }
	  }
  }

	printf("LIST OF GROUNDS SORTED ACCORDING TO STATE AND CITY NAMES\n :");

	for(i=0;i<20;i++)
	{
		if(g[i].groundName[0]!='\0')
		printf("\t%s\n",g[i].groundName) ;
	}

}
void isAvailable()
{
  char game[20];
  printf("ENTER GAMENAME:");
  scanf("%s",game) ;


  char date[9];
  int time;
  printf("ENTER DATE IN YYYYMMDD FORMAT :");
  scanf("%s",date) ;
  printf("enter time in TTTT format :");
  scanf("%s",time);

    int i,j,k;

    struct ground temp;
    //sort acc to state
    for(i=0;i<20;i++)
    {
    	for(j=i;j<20-i-1;j++)
    	{
    		if(strcmp(g[j].stateName,g[j+1].stateName)>0)
    		{
  	   		temp=g[j];
  	   		g[j]=g[j+1];
  	   		g[j+1]=temp;
  	    }
  	  }
    }
  //sort acc to city
    for(i=0;i<20;i++)
    {
    	for(j=i;j<20-i-1;j++)
    	{
    		if(strcmp(g[j].stateName,g[j+1].stateName)==0)
    		{
  		  	if(strcmp(g[j].cityName,g[j+1].cityName)>0)
    			{
  	   			temp=g[j];
  	   			g[j]=g[j+1];
  	   			g[j+1]=temp;
  	    	}
  		  }
  	  }
    }

    //print according to date and time

    for(i=0;i<20;i++)
    {
      for(j=0;j<5;j++)
      {

          if(strcmp(g[i].sports[j].d,date)==0)
          if(g[i].sports[j].stTime==time)
          printf("\t%s\n",g[i].groundName);

      }
    }


}
void FindLocationsForGameEvents(){

  char game[20];
  printf("ENTER GAMENAME:") ;
  scanf("%s",game);

	int i,j,k;

  char date1[8],date2[8];
  int time1,time2;
  printf("enter range of dates in YYYYMMDD format :");
  scanf("%s %s",date1,date2) ;
  printf("enter starting time in TTTT format :");
  scanf("%s",time1);
  printf("enter ending time in TTTT format :");
  scanf("%s",time2);

  for(i=0;i<20;i++)
  {

		for(k=0;k<150;k++)
		{
        if(strcmp(g[i].sports[j].gameName,game)==0)
        {
					if(strcmp(g[i].bg[k].bdate,date1)>0&&strcmp(g[i].bg[k].bdate,date2)<0)
					{
						if((g[i].bg[k].start>time1) && (g[i].bg[k].start<time2))
						{
							printf("\t%s\n",g[i].groundName);
						}
          }
        }
    }
  }

}
void ClashOfMatches()
{
  char date[20] ;
  printf("ENTER DATE IN YYYYMMDD FORMAT :") ;
  scanf("%s",date) ;

  char game[20] ;
  printf("ENTER GAME :") ;
  scanf("%s",game) ;

  int i,j,k;
  int count=0;

  printf("THE LIST OF CLASHING MATCHES ARE :") ;
  //for accessing struct ground
  for(i=0;i<20;i++)
  {
    //for accessing struct bookgames
      for(j=0;j<150;j++)
      {
        if(strcmp(g[i].bg[j].sportsName,game)==0)
        {
          if(strcmp(g[i].bg[j].bdate,date)==0)
          {
            if(count==0)
            {
            printf("\tTHE LIST OF CLASHING MATCHES IN %s ARE : ",g[i].groundName);
            }
            printf("\t\t%s\n",g[i].bg[j].sportsName);
            count++;
          }
        }
      }
      count=0;
  }

}
void GiveListOfGroundsHavingMinOneMatch()
{
  int i,j,k;

  struct GameList{
    char games[20];
  }gl[20];

  int n;
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    scanf("%s",gl[i].games);
  }

  char date[9];
  scanf("%s",date) ;

  char city[20];
  scanf("%s",city);

  int l;
	int count=0;
  for(i=0;i<n;i++)
  {
    for(k=0;k<20;k++)
    {
      for(j=0;j<150;j++)
      {
        if(strcmp(gl[i].games,g[k].bg[j].sportsName)==0)
        {
          if(strcmp(city,g[k].cityName)==0)
          {
              if(strcmp(date,g[k].bg[j].bdate)==0)
              {
              	count++;
               
              }
          }
        }
      }
      
      if(count>=1)
       printf("\t%s\n",g[k].groundName);
    }
    count=0;
  }
}
void GiveListOfGroundsHavingAtleastKMatches()
{
  int i,j,k;

  struct GameList{
    char games[20];
  }gl[20];

  int n;
  printf("ENTER NO. OF GAMES TO BE ENTERED IN THE LIST:");
  scanf("%d",&n);
  printf("ENTER GAMES :") ;
  for(i=0;i<n;i++)
  {
    scanf("%s",gl[i].games);
  }

  char date[9];
  printf("ENTER DATE IN YYYYMMDD FORMAT :") ;
  scanf("%s",date) ;

  char city[20];
  printf("ENTER CITYNAME :");
  scanf("%s",city);

  int kmin;
  printf("ENTER THE VALUE OF K :");
  scanf("%d",&kmin) ;

  int l;

  int count=0;

  for(i=0;i<n;i++)
  {
    for(k=0;k<20;k++)
    {
      for(j=0;j<150;j++)
      {
        if(strcmp(gl[i].games,g[k].bg[j].sportsName)==0)
        {
          if(strcmp(city,g[k].cityName)==0)
          {
              if(strcmp(date,g[k].bg[j].bdate)==0)
              {
                count++;
              }
          }
        }
      }

      if(count>=kmin)
      {
        printf("\t%s\n",g[k].groundName) ;
      }
     
    }
     count=0;
  }
}
void SortOnPriceForAGame()
{
  int i,j,k;
  char game[20];
  printf("ENTER GAMENAME :") ;
  scanf("%s",game);

  char date[9] ;
  int time;
  printf("ENTER DATE YYYYMMDD AND TIME TTTT :");
  scanf("%s%s",date,time) ;

  struct games temp;


    for(j=0;j<20-i-1;j++)
    {
      for(k=0;k<5;k++)
      {
        for(i=0;i<5-k-1;i++)
        {
          if(g[j].sports[k].rate>g[j].sports[k+1].rate)
          {
            temp=g[j].sports[k];
            g[j].sports[k]=g[j].sports[k+1];
            g[j].sports[k+1]=temp;
          }
        }
      }
    }

    int count=0;

    for(i=0;i<20;i++)
    {
      for(j=0;j<5;j++)
      {
        if(strcmp(g[i].sports[j].gameName,game)==0)
        {
          if(strcmp(g[i].sports[j].d,date)==0&&g[i].sports[j].stTime==time)
          {
          count++;
          }
        }
      }

      if(count>0)
      printf("\t%s\n",g[i].groundName);
    }

}
void FindGamesSchedule()
{
  //GAMELIST
  struct listOfGames{
    char game[20] ;
    char date[9];
    int time;
  }log[20];

  int i;
  for(i=0;i<20;i++)
  {
    log[i].game[0]='\0';
    log[i].date[0]='\0';
    log[i].time=0;
  }

  int j,k;

  //TAKE LIST OF GAMES AS INPUT
  int n;
  printf("ENTER NO. OF GAMES TO BE ENTERED :") ;
  scanf("%d",&n) ;
  printf("ENTER QUERIES GAME,DATE YYYYMMDD, TIME TTTT FORMAT");
  for(i=0;i<n;i++)
  {
    scanf("%s",log[i].game);
    scanf("%s",log[i].date);
    scanf("%d",log[i].time);
  }
  int c;
  int min=20000;
  int sum=0;
  int j2,k2;
  int flag;
  for(i=0;i<n;i++)
  {
      for(j=0;j<20;j++)
      {
        for(k=0;k<5;k++)
        {
          flag=0;
          //COMPARING DATE AND TIME QUERYS WITH THE ENTRIES IN DATABASE
          if(strcmp(log[i].game,g[j].sports[k].gameName)==0)
          {
            if(log[i].time==g[j].sports[k].stTime)
            {
              c=g[j].sports[k].endTime-g[j].sports[k].stTime ;
              if(((g[j].sports[k].rate*c)/100)<min)
                {
                  min=g[j].sports[k].rate;
                  j2=j;
                  k2=k;
                  flag=1;
                }

            }
          }
        }

        if(flag==1)
        {
        sum=sum+min;
        printf("GROUND %s IS ALLOTED TO %s GAME",g[j2].groundName,log[i].game);
        }
      }

  }

  printf("THE MINIMUM SUM IS %d",sum) ;
}
void enterValuesIntoDatabase()
{
	strcpy(g[0].groundName,"Wankhede stadium");
	strcpy(g[0].cityName,"Mumbai");
	strcpy(g[0].stateName,"Maharashtra");
	strcpy(g[0].sports[0].gameName,"Cricket");
	strcpy(g[0].sports[1].gameName,"Basketball");
	strcpy(g[0].sports[2].gameName,"Football");
	strcpy(g[0].sports[3].gameName,"Tabletennis");
	strcpy(g[0].sports[4].gameName,"Badminton");
	strcpy(g[0].sports[0].d,"20171201"); //in yyyymmdd FORMAT
		strcpy(g[0].sports[1].d,"20170314"); //in yyyymmdd FORMAT
			strcpy(g[0].sports[2].d,"20171101"); //in yyyymmdd FORMAT
				strcpy(g[0].sports[3].d,"20171001"); //in yyyymmdd FORMAT
					strcpy(g[0].sports[4].d,"20170901"); //in yyyymmdd FORMAT
		g[0].sports[0].stTime=900; //in tttt FORMAT
		g[0].sports[1].stTime=1000; //in tttt FORMAT
		g[0].sports[2].stTime=1100; //in tttt FORMAT
		g[0].sports[3].stTime=1200; //in tttt FORMAT
		g[0].sports[4].stTime=1300; //in tttt FORMAT

		g[0].sports[0].endTime=1000; //in tttt FORMAT
		g[0].sports[1].endTime=1100; //in tttt FORMAT
		g[0].sports[2].endTime=1200; //in tttt FORMAT
		g[0].sports[3].endTime=1300; //in tttt FORMAT
		g[0].sports[4].endTime=1400; //in tttt FORMAT


		strcpy(g[0].bg[0].sportsName,"Cricket");
		strcpy(g[0].bg[0].bdate,"20171201");
		g[0].bg[0].start=900;
		g[0].bg[0].end=1000;

		strcpy(g[0].bg[1].sportsName,"Khokho");
		strcpy(g[0].bg[1].bdate,"20170604");
		g[0].bg[1].start=1000;
		g[0].bg[1].end=1100;

		strcpy(g[0].bg[2].sportsName,"Badminton");
		strcpy(g[0].bg[2].bdate,"20171102");
		g[0].bg[2].start=900;
		g[0].bg[2].end=1000;

		g[0].sports[0].rate=100;
		g[0].sports[1].rate=200;
		g[0].sports[2].rate=500;
		g[0].sports[2].rate=200;
		g[0].sports[4].rate=300;


	strcpy(g[1].groundName,"Wellington stadium");
	strcpy(g[1].cityName,"Dehradun");
	strcpy(g[1].stateName,"Uttarakhand");
	strcpy(g[1].sports[0].gameName,"Cricket");
	strcpy(g[1].sports[1].gameName,"Basketball");
	strcpy(g[1].sports[2].gameName,"Football");
	strcpy(g[1].sports[3].gameName,"Tabletennis");
	strcpy(g[1].sports[4].gameName,"Khokho");
	strcpy(g[1].sports[0].d,"20170101"); //in yyyymmdd FORMAT
		strcpy(g[1].sports[1].d,"20171121"); //in yyyymmdd FORMAT
			strcpy(g[1].sports[2].d,"20170301"); //in yyyymmdd FORMAT
				strcpy(g[1].sports[3].d,"20170801"); //in yyyymmdd FORMAT
					strcpy(g[1].sports[4].d,"20171207"); //in yyyymmdd FORMAT

					g[1].sports[0].stTime=900; //in tttt FORMAT
					g[1].sports[1].stTime=1000; //in tttt FORMAT
					g[1].sports[2].stTime=1100; //in tttt FORMAT
					g[1].sports[3].stTime=1200; //in tttt FORMAT
					g[1].sports[4].stTime=1300; //in tttt FORMAT

					g[1].sports[0].endTime=1000; //in tttt FORMAT
					g[1].sports[1].endTime=1100; //in tttt FORMAT
					g[1].sports[2].endTime=1200; //in tttt FORMAT
					g[1].sports[3].endTime=1300; //in tttt FORMAT
					g[1].sports[4].endTime=1400; //in tttt FORMAT

					strcpy(g[1].bg[0].sportsName,"Cricket");
					strcpy(g[1].bg[0].bdate,"20171201");
					g[1].bg[0].start=900;
					g[1].bg[0].end=1000;

					strcpy(g[1].bg[1].sportsName,"Khokho");
					strcpy(g[1].bg[1].bdate,"20170604");
					g[1].bg[1].start=1000;
					g[1].bg[1].end=1100;

					strcpy(g[1].bg[2].sportsName,"Badminton");
					strcpy(g[1].bg[2].bdate,"20171102");
					g[1].bg[2].start=900;
					g[1].bg[2].end=1000;

					g[1].sports[0].rate=100;
					g[1].sports[1].rate=200;
					g[1].sports[2].rate=500;
					g[1].sports[2].rate=200;
					g[1].sports[4].rate=300;



	strcpy(g[2].groundName,"Gavaskar maidan");
	strcpy(g[2].cityName,"Mumbai");
	strcpy(g[2].stateName,"Maharashtra");
	strcpy(g[2].sports[0].gameName,"Cricket");
	strcpy(g[2].sports[1].gameName,"Javelin Throw");
	strcpy(g[2].sports[2].gameName,"Football");
	strcpy(g[2].sports[3].gameName,"Shortput");
	strcpy(g[2].sports[4].gameName,"Khokho");
	strcpy(g[2].sports[0].d,"20171109"); //in yyyymmdd FORMAT
		strcpy(g[2].sports[1].d,"20171215"); //in yyyymmdd FORMAT
			strcpy(g[2].sports[2].d,"20170601"); //in yyyymmdd FORMAT
				strcpy(g[2].sports[3].d,"20170701"); //in yyyymmdd FORMAT
					strcpy(g[2].sports[4].d,"20170608"); //in yyyymmdd FORMAT

					g[2].sports[0].stTime=900; //in tttt FORMAT
					g[2].sports[1].stTime=1000; //in tttt FORMAT
					g[2].sports[2].stTime=1100; //in tttt FORMAT
					g[2].sports[3].stTime=1200; //in tttt FORMAT
					g[2].sports[4].stTime=1300; //in tttt FORMAT

					g[2].sports[0].endTime=1000; //in tttt FORMAT
					g[2].sports[1].endTime=1100; //in tttt FORMAT
					g[2].sports[2].endTime=1200; //in tttt FORMAT
					g[2].sports[3].endTime=1300; //in tttt FORMAT
					g[2].sports[4].endTime=1400; //in tttt FORMAT

					strcpy(g[2].bg[0].sportsName,"Cricket");
					strcpy(g[2].bg[0].bdate,"20171201");
					g[2].bg[0].start=900;
					g[2].bg[0].end=1000;

					strcpy(g[2].bg[1].sportsName,"Kabaddi");
					strcpy(g[2].bg[1].bdate,"20170604");
					g[2].bg[1].start=1000;
					g[2].bg[1].end=1100;

					strcpy(g[2].bg[2].sportsName,"Swimming");
					strcpy(g[2].bg[2].bdate,"20171102");
					g[2].bg[2].start=900;
					g[2].bg[2].end=1000;

					g[2].sports[0].rate=100;
					g[2].sports[1].rate=200;
					g[2].sports[2].rate=500;
					g[2].sports[2].rate=200;
					g[2].sports[4].rate=300;


	strcpy(g[3].groundName,"Rajiv Gandhi Stadium");
	strcpy(g[3].cityName,"Hyderabad");
	strcpy(g[3].stateName,"Telangana");
	strcpy(g[3].sports[0].gameName,"Softball");
	strcpy(g[3].sports[1].gameName,"Football");
	strcpy(g[3].sports[2].gameName,"Snooker");
	strcpy(g[3].sports[3].gameName,"Chess");
	strcpy(g[3].sports[4].gameName,"Cricket");

	strcpy(g[3].sports[0].d,"20171109"); //in yyyymmdd FORMAT
		strcpy(g[3].sports[1].d,"20171215"); //in yyyymmdd FORMAT
			strcpy(g[3].sports[2].d,"20170601"); //in yyyymmdd FORMAT
				strcpy(g[3].sports[3].d,"20170701"); //in yyyymmdd FORMAT
					strcpy(g[3].sports[4].d,"20170608"); //in yyyymmdd FORMAT

					g[3].sports[0].stTime=900; //in tttt FORMAT
					g[3].sports[1].stTime=1000; //in tttt FORMAT
					g[3].sports[2].stTime=1100; //in tttt FORMAT
					g[3].sports[3].stTime=1200; //in tttt FORMAT
					g[3].sports[4].stTime=1300; //in tttt FORMAT

					g[3].sports[0].endTime=1000; //in tttt FORMAT
					g[3].sports[1].endTime=1100; //in tttt FORMAT
					g[3].sports[2].endTime=1200; //in tttt FORMAT
					g[3].sports[3].endTime=1300; //in tttt FORMAT
					g[3].sports[4].endTime=1400; //in tttt FORMAT

					strcpy(g[3].bg[0].sportsName,"Cricket");
					strcpy(g[3].bg[0].bdate,"20171201");
					g[3].bg[0].start=900;
					g[3].bg[0].end=1000;

					strcpy(g[3].bg[1].sportsName,"Kabaddi");
					strcpy(g[3].bg[1].bdate,"20170604");
					g[3].bg[1].start=1000;
					g[3].bg[1].end=1100;

					strcpy(g[3].bg[2].sportsName,"Swimming");
					strcpy(g[3].bg[2].bdate,"20171102");
					g[3].bg[2].start=900;
					g[3].bg[2].end=1000;

					g[3].sports[0].rate=100;
					g[3].sports[1].rate=200;
					g[3].sports[2].rate=500;
					g[3].sports[2].rate=200;
					g[3].sports[4].rate=300;

}
