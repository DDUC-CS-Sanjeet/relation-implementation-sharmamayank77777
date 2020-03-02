#include<iostream>
using namespace std;
class relation
{
	private:
	int size,l;
	int *arr1;
	int **arr2;
	public:
	relation()
	{
		size=0;
		l=0;
	}	
	relation(int s)
	{
		size=s;
		arr1=new int[size];
		arr2=new int*[0];
	}
	void input()
	{
			for(int i=0;i<size;i++)
			{
				cin>>arr1[i];
			}
		rem_dupl();
	}
	void rem_dupl()
		{
			for(int i=0;i<size-1;i++)
			{
				for(int j=i+1;j<size;j++)
				{
					if(arr1[i]==arr1[j])
					{
						for(int k=j;k<size;k++)
						arr1[k]=arr1[k+1];
						size--;
						i--;
					}
				}
			}
		}
		int card() const
		{
			return size;
		}
	 relation operator +(relation const &ob)
		{
			int s,s1,s2;
			s1=this->card();
			s2=ob.card();
			s=s1+s2;
			relation temp(s);
			int k=0;
			for(int i=0;i<this->size;i++)
			{
				temp.arr1[k++]=this->arr1[i];
			}
			for(int j=0;j<ob.size;j++)
			{
				temp.arr1[k++]=ob.arr1[j];
			}
			temp.rem_dupl();
			return temp;
		}
	void input_relation()
	{
		int i,a,b,n;
		char flag1,flag2;
		for(i=0;i<size;i++)
		{
			if(l<arr1[i])
			{
				l=arr1[i];
			}
		}
		
		arr2=new int*[l];
		for(int i=0;i<l;i++)
		arr2[i]=new int[i];
		
		for(int p=0;p<l;p++)
		{
			for(int k=0;k<l;k++)
			{
				arr2[p][k]=0;
			}
		}
	
		cout<<"Enter elements of relation:";
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			flag1=flag2=0;
			cout<<"Enter "<<j<<" pair:";
			cin>>a>>b;
			for(int i=0;i<size;i++)
			{
				if(arr1[i]==a )
				{
					flag1++;
					break;
				}
			}
			for(int i=0;i<size;i++)
			{
				if(arr1[i]==b )
				{
					flag2++;
					break;
				}
			}

			if(flag1!=0 && flag2!=0)
			{
				arr2[a-1][b-1]=1;									
			}
			else
			{
				cout<<"Given ordered pair not exist in relation";
				exit(1);
			}
		}
	}
	void reflexive()
	{
		int count=0;
		for(int i=0;i<l;i++)
		{
			if(arr2[i][i]==1)
			{
				count++;
			}
		}
		if(count<l)
		cout<<"\nGiven Relation is not Reflexive";
		else 
		cout<<"\nGiven Relation is Reflexive";
	}
	void symmetric()
	{
		int flag=-1;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<l;j++)
			{
				if(arr2[i][j]!=arr2[j][i])
				{
					flag=0;
				}
			}
		}
		if(flag==0)
		cout<<"\nGiven relation is not Symmetric";
		else
		cout<<"\nGiven relation is Symmetric";
	}
	void anti_symmetric()
	{
		int flag=-1;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<l;j++)
			{
				if(arr2[i][j]!=arr2[j][i] && i!=j)
				{
					flag=0;
				}
			}
		}
		if(flag==0)
		cout<<"\nGiven relation is not Anti-Symmetric";
		else
		cout<<"\nGiven relation is Anti-Symmetric";
	}
	void display()
	{
		cout<<"Matrix is:\n";
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<l;j++)
			{
				cout<<arr2[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
};
int main()
{
	int ch,n1,n2;
	cout<<"\t****   MENU    *****\n"
		<<"\t1.Relation in one set\n"
		<<"\t2.Relation b/w two sets:";
	cin>>ch;
	switch(ch)
	{
		case 1:		{
		
						cout<<"Enter size of set:";
						cin>>n1;
						relation ob(n1);
						cout<<"Enter ELEMENTS OF SETS:";
						ob.input();
						ob.input_relation();
						ob.reflexive();
						ob.symmetric();
						ob.anti_symmetric();
						break;
					}
						
		case 2:		{
						cout<<"Enter size of 1 set:";
						cin>>n1;
						cout<<"Enter size of 2 set:";
						cin>>n2;	
						relation ob1(n1),ob2(n2);
						cout<<"Enter 1 set:";
						ob1.input();
						cout<<"Enter 2 set:";
						ob2.input();
						ob1=ob1+ob2;
						ob1.input_relation();
						ob1.reflexive();
						ob1.symmetric();
						ob1.anti_symmetric();
						break;
					}
		default:		cout<<"Wrong choice!!";					
	}			
	return 0;
}
