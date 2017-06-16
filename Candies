int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long n;
    cin>>n;
    long rating[n];
    long candies[n];
    for(long i =0;i<n;i++){
        cin>>rating[i];
        candies[i] = 0;
    }
    candies[0]=1;
    for(long i = 1;i<n;i++){
        if(rating[i]>rating[i-1])
            candies[i] = candies[i-1]+1;
        else
            candies[i] = 1;
    }
    long total = candies[n-1];
    for(long i = n-2;i>=0;i--){
        if(rating[i+1]<rating[i] && candies[i]<=candies[i+1])
            candies[i] = candies[i+1]+1;
        total+=candies[i];
    }
    cout<<total;
    return 0;
}
