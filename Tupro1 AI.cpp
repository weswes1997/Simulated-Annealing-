#include<iostream>
#include <stdlib.h>
#include <tgmath.h>
using namespace std;
double fungsi(double x1, double x2)
{
    return (4-2.1*x1*x1+x1*x1*x1*x1/3)*x1*x1+x1*x2+(-4+4*x2*x2)*x2*x2;

}

double prob(double cost_now, double cost_l, double T){
    return exp(-(cost_l-cost_now)/T);
}
int main()
{
    double T=1000;
    double T_min=1;
    double alpha=0.99;
    double x1_g=rand() % 2001+(-1000);
    x1_g=x1_g/100;
    double x2_g=rand() % 2001+(-1000);
    x2_g=x2_g/100;
    double cost_g=fungsi(x1_g,x2_g);
    double x1_l=x1_g;
    double x2_l=x2_g;
    double cost_l=cost_g;
    double x1_now,x2_now,cost_now,bil_rand;

    while (T>=T_min)
    {
        {
            x1_now=rand() % 2001+(-1000);
            x1_now=x1_now/100;
            x2_now=rand() % 2001+(-1000);
            x2_now=x2_now/100;
            cost_now=fungsi(x1_now,x2_now);
            if (cost_now<cost_l)
            {
                x1_l=x1_now;
                x2_l=x2_now;
                cost_l=cost_now;
            }
            else
            {
                bil_rand=rand()% 100;
                double ap=prob(cost_now,cost_l,T)*100;
                if (bil_rand<ap)
                {
                    cost_l=cost_now;
                    x1_l=x1_now;
                    x2_l=x2_now;
                }
            }
            if (cost_now<cost_g)
            {
                x1_g=x1_now;
                x2_g=x2_now;
                cost_g=cost_now;
            }
        }
        T=alpha*T;
    }
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"      |            Fungsi minimum dengan nilai= "<<cost_g<<"               |"<<endl;
    cout<<"      |                 x1= "<<x1_g<<"                                       |"<<endl;
    cout<<"      |                 x2= "<<x2_g<<"                                        |"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    return 0;
}


