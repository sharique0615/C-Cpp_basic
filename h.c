#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_HEIGHT 100
struct MinHeapNode
{
    char data;
    unsigned freq;
    struct MinHeapNode *left,*right;
};
struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** arr;
};
struct MinHeapNode* newNode(char data,unsigned freq)
{
    struct MinHeapNode* temp=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left=temp->right=NULL;
    temp->data=data;
    temp->freq=freq;
    return temp;
}
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size=0;
    minHeap->capacity=capacity;
    minHeap->arr=(struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b)
{
    struct MinHeapNode* t=*a;
    *a=*b;
    *b=t;
}
void minHeapify(struct MinHeap* minHeap,int indx)
{
    int smallest=indx;
    int left=2*indx+1;
    int right=2*indx+2;
    if(left<minHeap->size && minHeap->arr[left]->freq<minHeap->arr[smallest]->freq)
        smallest=left;
    if(right<minHeap->size && minHeap->arr[right]->freq<minHeap->arr[smallest]->freq)
        smallest=right;
    if(smallest!=indx)
    {
        swapMinHeapNode(&minHeap->arr[smallest],&minHeap->arr[indx]);
        minHeapify(minHeap,smallest);
    }        
}
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size==1);
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->arr[0];
    minHeap->arr[0]=minHeap->arr[minHeap->size-1];
    --minHeap->size;
    minHeapify(minHeap,0);
    return temp;
}
void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i=minHeap->size-1;
    while(i && minHeapNode->freq<minHeap->arr[(i-1)/2]->freq)
    {
        minHeap->arr[i]=minHeap->arr[(i-1)/2];
        i=(i-1)/2;
    }
    minHeap->arr[i]=minHeapNode;
}
void buildMinHeap(struct MinHeap* minHeap)
{
    int n=minHeap->size-1;
    int i;
    for(i=(n-1)/2;i>=0;--i)
    minHeapify(minHeap,i);
}
void printArr(int ary[],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d",ary[i]);
    printf("\n");
}
int isLeaf(struct minHeapNode* root)
{
    return !(root->left)&&!(root->right);
}
struct MinHeap* creatAndBuildMinHeap(char data[],int freq[],int size)
{
    struct MinHeap* minHeap= createMinHeap(size);
    for(int i=0;i<size;i++)
    minHeap->arr[i]=newNode(data[i],freq[i]);
    minHeap->size=size;
    buildMinHeap(minHeap);
    return minHeap;
}
struct MinHeapNode *
buildHuffmanTree (char data[], 
int freq[], int size) 
 
{
  
struct MinHeapNode *left, *right, *top;
  
struct MinHeap *minHeap 
 = createAndBuildMinHeap (data, freq, size);
  
 
while (!isSizeOne (minHeap))
    {
      
 
left = extractMin (minHeap);
      
right = extractMin (minHeap);
      
 
 
top = newNode ('$', left->freq + right->freq);
      
 
top->left = left;
      
top->right = right;
      
 
insertMinHeap (minHeap, top);
    
}
  
 
return extractMin (minHeap);

}


 
 
void
printCodes (struct MinHeapNode *root, int ary[], 
int top) 
 
{
  
 
if (root->left)
    {
      
 
ary[top] = 0;
      
printCodes (root->left, ary, top + 1);
    
}
  
 
if (root->right)
    {
      
 
ary[top] = 1;
      
printCodes (root->right, ary, top + 1);
    
}
  
 
if (isLeaf (root))
    {
      
 
printf ("%c: ", root->data);
      
printAry (ary, top);
    
}

}


 
 
void
HuffmanCodes (char data[], int freq[], int size) 
 
{
  
 
struct MinHeapNode *root 
 = buildHuffmanTree (data, freq, size);
  
 
int ary[MAX_TREE_HEIGHT], top = 0;
  
 
printCodes (root, ary, top);

} 
 
int

main () 
{
  
 
char arr[] = { 'f', 'e', 'c', 'b', 'd', 'a' };
  
int freq[] = { 5, 9, 12, 13, 16, 45 };
  
 
int size = sizeof (ary) / sizeof (ary[0]);
  
 
HuffmanCodes (ary, freq, size);
  
 
return 0;

}

