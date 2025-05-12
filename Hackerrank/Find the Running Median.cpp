void insert_increase(vector<int> &H,int x){
    H.push_back(x);
    int i=H.size()-1;
    while (i>0) {
        if(H[i]<H[(i-1)/2]) swap(H[i],H[(i-1)/2]);
        else break;
        i=(i-1)/2;
    }
}
void insert_decrease(vector<int> &H,int x){
    H.push_back(x);
    int i=H.size()-1;
    while (i>0) {
        if(H[i]>H[(i-1)/2]) swap(H[i],H[(i-1)/2]);
        else break;
        i=(i-1)/2;
    }
}
void update1(vector<int> &H,int x){
    H[0]=x;
    int i=0;
    int n=H.size()-1;
    while (2*i+1<=n) {
        int max=i;
        if(H[2*i+1]>H[i]) max=2*i+1;
        if((2*i+2<=n)&(H[2*i+2]>H[max])) max=2*i+2;
        if(max!=i){
            swap(H[i],H[max]);
            i=max;
        }
        else break;
    }
}
void update2(vector<int> &H,int x){
    H[0]=x;
    int i=0;
    int n=H.size()-1;
    while (2*i+1<=n) {
        int min=i;
        if(H[2*i+1]<H[i]) min=2*i+1;
        if((2*i+2<=n)&(H[2*i+2]<H[min])) min=2*i+2;
        if(min!=i){
            swap(H[i],H[min]);
            i=min;
        }
        else break;
    }
}
vector<double> runningMedian(vector<int> a) {
    vector<int>H1;
    vector<int>H2;
    vector<double> v;
    v.push_back(a[0]);
    insert_decrease(H1,a[0]);
    for(int i=1;i<a.size();i++){
        if(i%2==0) insert_decrease(H1,a[i]);
        else insert_increase(H2,a[i]);
        
        if(H1[0]>H2[0]) {
            int temp=H1[0];
            update1(H1,H2[0]);
            update2(H2,temp);
        }
        if(i%2==0)v.push_back(double(H1[0]));
        else v.push_back(double((H1[0]+H2[0])/2.0));
    }
    return v;
}
return v;
}
