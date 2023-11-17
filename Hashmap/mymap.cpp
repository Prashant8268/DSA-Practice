#include<string>
#include<iostream>
using namespace std;

template<typename V>
class MapNode{

    string key;
    V value;
    MapNode* next;
    

    MapNode(string key, V value){
        this->key=key;
        this->value= value;
        this->next =NULL;
    }
    ~MapNode(){
        delete next;
    }



};


template<typename V>
class ourmap{

    
    MapNode<V>** buckets;
    int size;
    int numBuckets;

    public:

    ourmap(){

        count = 0;
        numBuckets = 5;
        for(int i=0; i<numBuckets; i++){
            buckets[i]=NULL;
        }
    }

    ~ourmap(){
        for(int i =0; i<numBuckets; i++){
        delete buckets[i];
        }
        delete [] buckets;
        }

        int size(){
            return count;
        }
        int getSize(){
            return count;
        }
        
        int getValue(string key){
            int bucketIndex = getBucketIndex(key);

            MapNode<V> * head= buckets[bucketIndex];


            while(head!=NULL){
                if(head->key==key){
                    return head->value;
                }
                head=head->next;

            }
            return 0;

        }


        private:


        int getBucketIndex(string key){

            int hashCode = 0;
            int currentCoeff =1;
            for(int i= key.length()-1; i>=0; i--){
                hashCode +=key[i]*currentCoeff;
                hashCode = hashCode % numBuckets;
                currentCoeff*=37;
                currentCoeff = currentCoeff % numBuckets;
            }


            return hashCode % numBuckets;

        }

        void rehash(){
            MapNode<V>** temp;
            temp = buckets;

            buckets = new MapNode<V> * [2*numBuckets];
            for(int i=0; i<2*numBuckets; i++){
            buckets[i]=NULL;
            }

            int oldBucketSize = numBuckets;
            numBuckets *=2;
            count =0;

            for(int i=0; i<oldBucketSize; i++){
                MapNode<V> * head = temp[i];
                while(head!=NULL){
                    insert(head->key,head->value);
                    head=head->next;
                }
                
            }
            for(int i=0; i<oldBucketCount; i++){
            MapNode<V> * head =  temp[i];
            delete head;
            }
            
            delete [] temp;
        }


        public:




        

    V remove(string key){
        int bucketIndex = getBucketIndex(key);

        MapNode<V> * head = buckets[bucketIndex];

        MapNode<V>  * prev = NULL;

        while(head!=NULL){
            if(head->key==key){

                if(prev==NULL){
                    bucket[bucketIndex]= head->next;
                }
                else{
                    prev=head;
                    head=head->next;
                }
                
                V value = head->value;
                head->next = NULL;
                delete head;
                return value;
            }

        }
        return 0;
    }


    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);

        MapNode<V> * head = buckets[bucketIndex];

        while(head!=NULL){
            if(head->key==key){
                head->value = value;
                return ;
            }
            head=head->next;
        }

        head = buckets[bucketIndex];

        MapNode<V>* node = new MapNode<V> * (key,value);
        node->next= head;
        buckets[bucketIndex]=node;
        count++;

            double loadFactor = (1.0*count)/numBuckets;
            if(loadFactor>0.7){
            rehash();
            }

        return ;

    }


    };
 

