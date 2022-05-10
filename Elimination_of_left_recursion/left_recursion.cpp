#include&lt;iostream&gt;
#include&lt;string&gt;
using namespace std;
int main()
{ string ip,op1,op2,temp;
int sizes[10] = {};
char c;
int n,j,l;
cout&lt;&lt;&quot;Enter the Parent Non-Terminal : &quot;;
cin&gt;&gt;c;
ip.push_back(c);
op1 += ip + &quot;\&#39;-&gt;&quot;;
ip += &quot;-&gt;&quot;;
op2+=ip;
cout&lt;&lt;&quot;Enter the number of productions : &quot;;
cin&gt;&gt;n;
for(int i=0;i&lt;n;i++)
{ cout&lt;&lt;&quot;Enter Production &quot;&lt;&lt;i+1&lt;&lt;&quot; : &quot;;
cin&gt;&gt;temp;
sizes[i] = temp.size();
ip+=temp;
if(i!=n-1)
ip += &quot;|&quot;;
}
cout&lt;&lt;&quot;Production Rule : &quot;&lt;&lt;ip&lt;&lt;endl;
for(int i=0,k=3;i&lt;n;i++)
{
if(ip[0] == ip[k])
{
cout&lt;&lt;&quot;Production &quot;&lt;&lt;i+1&lt;&lt;&quot; has left recursion.&quot;&lt;&lt;endl;
if(ip[k] != &#39;#&#39;)
{
for(l=k+1;l&lt;k+sizes[i];l++)
op1.push_back(ip[l]);
k=l+1;
op1.push_back(ip[0]);
op1 += &quot;\&#39;|&quot;;
}
}
else

{
cout&lt;&lt;&quot;Production &quot;&lt;&lt;i+1&lt;&lt;&quot; does not have left recursion.&quot;&lt;&lt;endl;
if(ip[k] != &#39;#&#39;)
{
for(j=k;j&lt;k+sizes[i];j++)
op2.push_back(ip[j]);
k=j+1;
op2.push_back(ip[0]);
op2 += &quot;\&#39;|&quot;;
}
else
{
op2.push_back(ip[0]);
op2 += &quot;\&#39;&quot;;
}}}
op1 += &quot;#&quot;;
cout&lt;&lt;&quot;The Grammar after Eliminating the Left-Recursion is&quot;&lt;&lt;endl;
cout&lt;&lt;op2&lt;&lt;endl;
cout&lt;&lt;op1&lt;&lt;endl;
return 0;}
