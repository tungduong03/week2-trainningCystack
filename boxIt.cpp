#include<bits/stdc++.h>

using namespace std;

class Box {
    private:
        int l, h, b;

    public:
    // Box();
    Box(){
        l = 0;
        h = 0;
        b = 0;
    }
    // Box(int,int,int);
    Box(int l, int h, int b) {
        this->l = l;
        this->h = h;
        this->b = b;
    }

    // Box(Box);
    Box(Box& B) {
		l = B.l;
		b = B.b;
		h = B.h;
	}

    // int getLength();
    int getLength(){
        return l;
    }

    // int getBreadth ();
    int getBreadth(){
        return b;
    }

    // int getHeight ();
    int getHeight(){
        return h;
    }

    // long long CalculateVolume();
    long long CalculateVolume(){
        return (long long)l*b*h;
    }


    bool operator<(Box &B) {
        if (l < B.l){
            return true;
        }
        else if (l == B.l){
            if (b < B.b){
                return true;
            }
            else if (b == B.b){
                if (h < B.h){
                    return true;
                }
            }
        }
        return false;
    }
};

    //Overload operator << as specified
    //ostream& operator<<(ostream& out, Box& B)
    ostream &operator<<(ostream &out, Box &B)
    {
        out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
        return out;
    };


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
