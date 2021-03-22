#include<stdio.h>
 
 
 
void swap(int * a,int * b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
 
void minheapify(int arr[], int n, int i)
{
    int smallest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
 
        
        minheapify(arr, n, smallest);
    } 
}
 
void maxheapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
   
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        maxheapify(arr, n, largest);
    } 
}
 
void insertminheap(int mn[],int n,int value)
{
    mn[n]=value;
    int i=n;
    int parent;
    while(i>0)
    { 
        if(i%2)
        parent=i/2;
        else
            parent=i/2-1;
        if(mn[parent]>mn[i])
        {
            swap(&mn[i],&mn[parent]);
            i=parent;
        }
        else
        {
            return;
        }
    }
}
 
void insertmaxheap(int mx[],int n,int value)
{
    mx[n]=value;
    int i=n;
    int parent;
    while(i>0)
    {
        if(i%2)
        parent=i/2;
        else
            parent=i/2-1;
        if(mx[parent]<mx[i])
        {
            swap(&mx[i],&mx[parent]);
            i=parent;
        }
        else
        {
            return;
        }
    }
}
 
 
int main()
{
    int n;
    scanf("%d%*c",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%*c",&a[i]);
    }
    int mn[n];
    int mx[n];
    int cn=0,cx=0;
    int ans[n];
    for(int i=0;i<n;i++)
    {
        int num=a[i];
        if(cx==0 || mx[0]>num)
        {
            insertmaxheap(mx,cx,num);
            cx++;
        }
        else
        {
            insertminheap(mn,cn,num);
            cn++;
        }
        if(cx>cn+1)
        {
            insertminheap(mn,cn,mx[0]);
            cn++;
            swap(&mx[0],&mx[cx-1]);
            cx--;
            maxheapify(mx,cx,0);
        }
        else if(cn>cx+1)
        {
            insertmaxheap(mx,cx,mn[0]);
            cx++;
            swap(&mn[0],&mn[cn-1]);
            cn--;
            minheapify(mn,cn,0);
        }
        if(cx==cn)
        {
            ans[i]= (mx[0]+mn[0])/2;
           // printf("%d ",(mx[0]+mn[0])/2 );
        }
        else if(cx>cn)
        {
            ans[i]=mx[0];
            //printf("%d ",mx[0]);
        } 
        else if(cn>cx)
        {
            ans[i]=mn[0];
            //printf("%d ",mn[0]);
        }
    }
    for (int i = 0; i < n-1; ++i)
    {
        printf("%d ",ans[i]);
    }
    printf("%d",ans[n-1]);
    
    return 0;
}