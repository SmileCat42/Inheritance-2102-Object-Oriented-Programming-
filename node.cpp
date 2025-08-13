#include <string.h>
#include <iostream>
using namespace std;

struct sode {
  int w;
  struct sode *link;
};

int getchoice(){
    int c;
    cout << "\nSelect choice\n";
    cout << "1. add data\n";
    cout << "2. delete node\n";
    cout << "3. insert node\n";
    cout << "4. delete all node\n";
    cout << "5. show data\n";
    cout << "6. sort data\n";
    cout << "7. save data to\n";
    cout << "8. open data to\n";
    cout << "9. end progeam\n";
    cin >> c;
    return c;
}

int adddata(struct sode* &head,int &n){
    struct sode *q=head;
    struct sode *p=new struct sode;
    p->w=n;
    p->link=NULL;
    if(q==NULL){
        head=p;
        n++;
        return 0;
    }
    while(q->link!=NULL){
        q=q->link;
    }
    q->link=p;
    n++;
    return 0;
}

int deletenode(struct sode* &head){
    struct sode *q=head;
    int x;
    cout << "value is u want to delete : ";
    cin >> x;
    if(x==q->w){
        head=head->link;
        delete(q);
        return 0;
    }
    struct sode *prv=NULL;
    while(q->w!=x){
        prv=q;
        q=q->link;
        if(q==NULL){
            cout << "not found\n";
            return 0; 
        }
    }
    if(q->w==x){
        prv->link=q->link;
        delete(q);
        return 0;
    }else{
        cout << "not found\n";
    }
    return 0;
}

int showdata(struct sode *head){
    if(head==NULL){
        cout << "no data" << endl;
        return 0;
    }
    while(head!=NULL){
        cout << "Node : " << head->w << endl;
        head=head->link;
    }
    return 0;
}

void deleteallnode(struct sode* &head){
    while(head!=NULL){
        struct sode *q=head;
        head=head->link;
        delete(q);
    }
}

int insertnode(struct sode* &head){
    int x,y,z;
    struct sode *p=new struct sode;
    struct sode *q=head;
    cout << "input value : ";
    cin >> x;
    p->w=x;
    p->link=NULL;
    do{
    cout << "1. before or 2. after : ";
    cin >> y;
    }while(y<1 || y>2);
    struct sode *prv=NULL;
    if(head==NULL){
        cout << "add data first!" << endl;
        return 0;
    }
    if(y==1){
        cout << "before node : ";
        cin >> z;
        if(z==q->w){
            p->link=head;
            head=p;
            return 0;
        }
        while(q->w!=z){
            prv=q;
            q=q->link;
            if(q==NULL){
                cout << "not found " << z << endl;
                return 0;
            }
        }
        p->link=q;
        prv->link=p;
        return 0;
    }
    if(y==2){
        cout << "after node : ";
        cin >> z;
        while(q->w!=z){
            q=q->link;
            if(q==NULL){
                cout << "not found" << endl;
                return 0;
            }
        }
        p->link=q->link;
        q->link=p;
        return 0;
    }
    return 0;
}

void swap(struct sode* &q,struct sode* &run){
    int more;
    more=q->w;
    q->w=run->w;
    run->w=more;
}

void sortdata(struct sode *head){
    struct sode *q=head;
    while(q!=NULL){
        struct sode *run=q->link;
        while(run!=NULL){
            if(run->w > q->w){
                swap(q,run);
            }
            run=run->link;
        }
        q=q->link;
    }
}

int writedata(char *ff, struct sode *head){
    struct sode *q=head;
    FILE *fp;
    fp=fopen(ff,"wt");
    if(fp==NULL){
        cout << "cant open file" << endl;
        return 0;
    }
    while(q!=NULL){
        char node[10]={"Node :"};
        int x;

        x=q->w;

        fprintf(fp,"%s\t%d\n",node,x);
        q=q->link;
    }
    fclose(fp);
    return 0;
}

int readdata(char *ff,struct sode* &head){
    FILE *fp=fopen(ff,"rt");
    if(fp==NULL){
        cout << "cant open file" << endl;
        return 0;
    }
    while(!feof(fp)){
        struct sode *p=new struct sode;
        struct sode *q=head;
        char node[10];
        char sign[5];
        int x;
        fscanf(fp,"%s %s %d\n",&node,&sign,&x);
        p->w=x;
        p->link=NULL;
        if(q==NULL){
            head=p;
        }
        struct sode *prv=NULL;
        while(q!=NULL){
            q=q->link;
        }
        q->link=p;
    }
    
    fclose(fp);
    return 0;
}


int main()
{
    struct sode *head=NULL;
    int c=0;
    int n=1;
    do
    {
        c = getchoice();
        switch(c){
            case 1 : adddata(head,n);
                    break;
            case 2 : deletenode(head);
                    break;
            case 3 : insertnode(head);
                    break;
            case 4 : deleteallnode(head);
                    break;
            case 5 : showdata(head);
                    break;
            case 6 : sortdata(head);
                    break;
            case 7 : writedata("C:/Users/Windows10/Documents/yeyyey.txt",head);
                    break;
            case 8 : readdata("C:/Users/Windows10/Documents/yeyyey.txt",head);
                    break;
        }
    }while(c>0 && c<=8);
    return 0;
}