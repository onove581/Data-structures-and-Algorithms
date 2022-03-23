#include<bits/stdc++.h> 
using namespace std;  
struct et 
{ 
    char value; 
    et* left, *right; 
}; 
bool isOperator(char c) 
{ 
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
}  
void inorder(et *t) 
{ 
    if(t) 
    { 
        inorder(t->left); 
        printf("%c ", t->value); 
        inorder(t->right); 
    } 
} 
et* newNode(int v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
};  
et* constructTree(char postfix[]) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
    for (int i=0; i<strlen(postfix); i++) 
    { 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(postfix[i]); 
            t1 = st.top();  
            st.pop();    
            t2 = st.top(); 
            st.pop(); 
            t->right = t1; 
            t->left = t2; 
            st.push(t); 
        } 
    } 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 
int main() 
{ 
    char postfix[] = "ABC+/DE*+AC*-"; 
    // Thay abcde bang cac so  A=6, B=1, C=2, D=3, E=2
    char postifixnumber[]="612+/32*+62*-";
    
    et* r = constructTree(postfix); 
    printf("\n infix co ket qua la \n"); 
    inorder(r);
    et* k = constructTree(postifixnumber); 
    printf("\n infix co ket qua theo so la \n");
     
    inorder(k);
    return 0; 
} 


