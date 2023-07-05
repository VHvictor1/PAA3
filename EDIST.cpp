#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casosTeste;
    scanf("%d",&casosTeste);
    while(casosTeste--)
    {
        string palavra1,palavra2;
        cin >> palavra1;
        cin >> palavra2;
        int tamanho1 = palavra1.size();
        int tamanho2 = palavra2.size();
        vector<int> v1(tamanho2+9),v2(tamanho2+9);
        for(int i=0;i<=tamanho2;i++)
            v1[i] = i;
        for(int i=0;i<tamanho1;i++)
        {
            v2[0] = i+1;
            for(int j=0;j<tamanho2;j++)
            {
                int add;
                if(palavra1[i] == palavra2[j])
                    add = 0;
                else 
                    add = 1;
                v2[j+1] = min(v2[j]+1,min(v1[j+1]+1,v1[j]+add));
            }
            for(int i=0;i<tamanho2;i++)
                v1[i] = v2[i];
        }
        printf("%d\n",v2[tamanho2]);
    }
    return 0;
}