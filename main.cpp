#include "tree.h"



const char* default_image_file=srcPath("/image_noir_et_blanc.jpg");


int main(){

    true? cout<<"s",cout<<"e":cout<<"f",cout<<"j";
    string image_file = (argc>1)? argv[1]: default_image_file;
    byte* image;
    int width, height;
    cout << "Loading image: " << image_file << endl;
    if(! loadGreyImage(image_file, image, width, height)) {
        cerr << "Error loading image file " << image_file << endl;
        return 1;
    }

//    Window window = openWindow(width, height);
//    putGreyImage(IntPoint2(0,0), image, width, height);

    int N=width*height;
    int* V=new int [N];
    Attributes* att=new Attributes[N];
    int* M=new int [N];
    int* lowest_node=new int [N];
    Node* Nodes=new Node [N];
    for (int i=0;i<N;i++)
        V[i]=i;
    int root=-1;
    BuildComponentTree(V,width,height,image,att,Nodes,root,M,lowest_node);

    cout<<computeVolume(&Nodes[root])<<endl;

    for (int i=0;i<N;i++){
        Nodes[lowest_node[M[i]]].addPixel(i);
    }
    byte* image_rebuilt=new byte[N];

    drawTree(image_rebuilt,Nodes[root]);

    Window window = openWindow(width, height);
    putGreyImage(IntPoint2(0,0), image_rebuilt, width, height);

    bool keep_going=true;
    int x,y,z;
    while(keep_going){
        if(anyGetMouse(x,y,window,z)==3)
            keep_going=false;
        Node n = Nodes[lowest_node[M[x+width*y]]]; //Root of the partial tree containing this pixel

    }



    endGraphics();

    delete [] V;
    delete [] att;
    delete [] M;
    delete [] lowest_node;
    delete [] Nodes;
    delete default_image_file;



    return 0;
}
