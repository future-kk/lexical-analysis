#include <stdio.h>
#include <string.h>
char *g[11]={"void","int","float","char","if","else","while","do","for","return","main"};
int nm[11]={3,4,5,6,7,8,9,10,11,12,13};
int main()
{
    char str[85];
    char ss[80];
    memset(str,0,sizeof(str));
    while(gets(str)!=NULL)
    {
        int i,j,t,len;
        memset(ss,0,sizeof(ss));//把字符置为空串
        len=strlen(str);
        j=0;
        t=0;
        for(i=0;i<len;i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))//若第一个字符为字母，则可能为标识符或者关键字
            {
               for(;i<len;i++)
               {
                   if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='0'&&str[i]<='9'))//标识符可以由数字组成
                   {
                       ss[j++] = str[i];          //所有的满足条件的保存在ss数组里
                   }
                   else            //遇到的第一个非字母非数字非下划线 退出循环
                   {
                       break;
                   }
               }
               ss[j]='\0';
               //判断是否是关键字
               if(j==1){
                    if(ss[0]>='a'&&ss[0]<='z')    printf("<1,%c>,",ss[0]);
               }
               else{
                    int q;
                    for(q=0;q<11;q++){
                        if(strcmp(ss,g[q])==0)
                        {
                            printf("<%d,->,",nm[q]);
                            break;
                        }
                    }
                    if(q==11){
                        printf("<1,%s>",ss);
                    }
               }
               memset(ss,0,sizeof(ss));   //字符数组保存为空串，以免影响下一次的判断
               j = 0;
               i = i - 1;
            }
            else if(str[i]=='('||str[i]==')'||str[i]=='['||str[i]==']'||str[i]=='{'||str[i]=='}'||str[i]==','||str[i]==';')
            {
                    if(str[i]=='(') printf("<28,->");
                    if(str[i]==')') printf("<29,->");
                    if(str[i]=='[') printf("<30,->");
                    if(str[i]==']') printf("<31,->");
                    if(str[i]=='{') printf("<32,->");
                    if(str[i]=='}') printf("<33,->");
                    if(str[i]==';') printf("<34,->");
                    if(str[i]==',') printf("<35,->");
            }
            else if(str[i]>='0'&&str[i]<='9')
            {
                if(str[i+1]>'a'&&str[i+1]<'z'){
                        //printf("%c\n",str[i+1]);
                    for(t=i+1;t<len;t++){
                        if(str[t]<'z'&&str[t]>'a')
                            continue;
                        else{
                            i=t-1;
                            break;
                            }
                    }
                    printf("LexicalError,");
                }
                else
                {
                    for(;i<len;i++)
                    {
                        if(str[i]>='0'&&str[i]<='9')        //把所有整数保存到ss数组里
                        {
                            ss[j++]=str[i];
                        }
                        else
                        {
                            break;
                        }
                    }
                    ss[j]='\0';
                    printf("<2,%s>,",ss);
                    memset(ss,0,sizeof(ss));
                    j=0;
                    i=i-1;
                    }
            }
            else if(str[i]=='/'&&str[i+1]=='/') break;
            else if(str[i]=='*'&&str[i+1]=='/') break;
            else if(str[i]=='#') break;
            else    //若是运算符
            {
                if(str[i]=='+') printf("<14,->,");
                if(str[i]=='-') printf("<15,->,");
                if(str[i]=='*') printf("<16,->,");
                if(str[i]=='/') printf("<17,->,");
                if(str[i]=='%') printf("<18,->,");
                else
                {
                    if(str[i]=='<'&&str[i+1]!='=') printf("<19,->,");
                    if(str[i]=='<'&&str[i+1]=='=') printf("<20,->,");
                    if(str[i]=='>'&&str[i+1]!='=') printf("<21,->,");
                    if(str[i]=='>'&&str[i+1]=='=') printf("<22,->,");
                    if(str[i]=='='&&str[i+1]=='=') printf("<23,->,");
                    if(str[i]=='!'&&str[i+1]=='=') printf("<24,->,");
                    if(str[i]=='&'&&str[i+1]=='&') printf("<25,->,");
                    if(str[i]=='='&&str[i+1]!='=') printf("<27,->,");
                }
            }

        }
        memset(str,0,sizeof(str));
    }
    return 0;
}
