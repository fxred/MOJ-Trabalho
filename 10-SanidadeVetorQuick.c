#include <stdio.h>

typedef struct node {
    long unsigned int curr;
    long unsigned int prev;
    long unsigned int post;
} node;

node n[700000];

typedef node Item;

#define Key(A) (A.curr)
#define less(A, B) (Key(A) < Key(B))
#define lessequal(A, B) (Key(A) <= Key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

//Versão Otimizada
// int Separa(Item *n, int l, int r){
//     Item pivo = n[r];
    
//     int j = l;

//     for(int i = l; i < r; i++){
//         if(lessequal(n[i], pivo)){
//             exch(n[i], n[j]);
//             j++;
//         }
//     }

//     exch(n[j], n[r]);
    
//     return j;
// }

int separa(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}

void insertionsort(Item *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-1],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; Item tmp=v[j];
    while(less(tmp,v[j-1]))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}

static void quicksortM3(Item *V,int l, int r)
{
  if (r-l<=32) return;

  exch(V[(l+r)/2],V[r-1]);
  cmpexch(V[l],V[r-1]);
  cmpexch(V[l],V[r]);
  cmpexch(V[r-1],V[r]);


  int j=separa(V,l+1,r-1);
  quicksortM3(V,l,j-1);
  quicksortM3(V,j+1,r);
}

void quicksortM3insertion(Item *V,int l,int r)
{
  quicksortM3(V,l,r);
  insertionsort(V,l,r);
}



// void quicksort(node *n, int l, int r){
//     if(r <= l){return;}

//     cmpexch(n[((l + r)/ 2)], n[r]);
//     cmpexch(n[l], n[((l + r)/ 2)]);
//     cmpexch(n[r], n[((l + r)/ 2)]);
    
//     int j = Separa(n, l, r);
//     quicksort(n, l, (j - 1));
//     quicksort(n, (j + 1), r);
// }


int binarySearch(node *n, int l, int r, long unsigned int find) {
    if (r >= l) {
        int m = (r+l)/2;
        if (n[m].curr == find) {
            return m;
        }
        else if (n[m].curr > find) {
            binarySearch(n, l, m-1, find);
        }
        else if (n[m].curr < find) {
            binarySearch(n, m+1, r, find);
        }
    }
    else {
        return -1;
    }
}

void checkSanity(long unsigned int * firstNode, long unsigned int * lastNode, node *n, int size) {
    if (firstNode[2] == lastNode[0]) {
        if (firstNode[0] == lastNode[1]) {
            printf("sana\n");
            return;
        }
        else {
            printf("insana\n");
            return;
        }
    }

    int index;

    index = binarySearch(n, 0, size, firstNode[2]);
    //printf("%d\n", index);

    if (index == -1) {
        printf("insana\n");
        return;
    }

    else if (firstNode[2] == n[index].curr) {
        firstNode[0] = n[index].curr;
        firstNode[1] = n[index].prev;
        firstNode[2] = n[index].post;
        checkSanity(firstNode, lastNode, n, size);
    }

}


int main() {

    long unsigned int curr, prev, post;
    long unsigned int firstNode[3];
    long unsigned int lastNode[3];
    scanf("%lx %lx %lx", &firstNode[0], &firstNode[1], &firstNode[2]);
    scanf("%lx %lx %lx", &lastNode[0], &lastNode[1], &lastNode[2]);

    int i = 0;

    while (scanf("%lx %lx %lx", &curr, &prev, &post) == 3) {
        n[i].curr = curr;
        n[i].prev = prev;
        n[i++].post = post;
    }

    quicksortM3insertion(n, 0, i-1);

    // for (int j = 0; j < i; j++) {
    //     printf("%lx %lx %lx\n", n[j].curr, n[j].prev, n[j].post);
    // }
    checkSanity(firstNode, lastNode, n, i);
}