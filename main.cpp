/* 
 * File:   main.cpp
 * Author: regis
 *
 * Created on 13 de Dezembro de 2013, 11:48
 */

/* 
 * File:   main.cpp
 * Author: regis
 *
 * Created on 4 de Dezembro de 2013, 12:36
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

/*
 * 
 */
typedef struct puzzle{
  int board[3][3];
  struct puzzle *one, *two, *three;
  struct puzzle *father;
} Puzzle;
void print(Puzzle* nodo);
void shuffle(Puzzle* nodo);
void isSolution(Puzzle *nodo);
void copy(Puzzle* origin, Puzzle* destiny);
int h(Puzzle *nodo);// soma dos quadrados que estão em posição invalida
int h2(Puzzle *nodo); // Manhattan Distancia
void Astar(Puzzle start);

void shuffle(Puzzle* nodo){
    int rnd,y,x;
    bool n = false;
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if(nodo->board[j][k] == 0){  
                    x = j;
                    y = k;
                    n = true;
                }
            }
            if(n){
                break;
            }
        }
        n = false;
        
        if(x == 0 && y == 0){
            rnd =rand()%2+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[0][1];
                nodo->board[0][1] = 0;
            }else{
                nodo->board[x][y] = nodo->board[1][0];
                nodo->board[1][0] = 0;    
            }
          
        }
        if(x == 0 && y == 2) {
            rnd =rand()%2+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[0][1];
                nodo->board[0][1] = 0;
            }else{
                nodo->board[x][y] = nodo->board[1][2];
                nodo->board[1][2] = 0;    
            }
           
        }
        if(x == 2 && y == 0){
            rnd =rand()%2+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[1][0];
                nodo->board[1][0] = 0;
            }else{
                nodo->board[x][y] = nodo->board[2][1];
                nodo->board[2][1] = 0;    
            }
           
        }
        if(x == 2 && y == 2){
            //cout << "aui";
            rnd =rand()%2+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[1][2];
                nodo->board[1][2] = 0;
            }else{
                nodo->board[x][y] = nodo->board[2][1];
                nodo->board[2][1] = 0;    
            }
            
        }
        if(x == 0 && y == 1){
            rnd = rand()%3+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[0][0];
                nodo->board[0][0] = 0;
            }else if(rnd == 2){
                nodo->board[x][y] = nodo->board[0][2];
                nodo->board[0][2] = 0;
            }else{
                nodo->board[x][y] = nodo->board[1][1];
                nodo->board[1][1] = 0;
            }
            
        }
        if(x == 1 && y == 0 ){
            rnd = rand()%3+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[0][0];
                nodo->board[0][0] = 0;
            }else if(rnd == 2){
                nodo->board[x][y] = nodo->board[1][1];
                nodo->board[1][1] = 0;
            }else{
                nodo->board[x][y] = nodo->board[2][0];
                nodo->board[2][0] = 0;
            }
            
        }
        if(x == 1 && y == 2){
            rnd = rand()%3+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[0][2];
                nodo->board[0][2] = 0;
            }else if(rnd == 2){
                nodo->board[x][y] = nodo->board[2][2];
                nodo->board[2][2] = 0;
            }else{
                nodo->board[x][y] = nodo->board[1][1];
                nodo->board[1][1] = 0;
            }
           
        }
        if(x == 2 && y == 1){
            rnd = rand()%3+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[2][0];
                nodo->board[2][0] = 0;
            }else if(rnd == 2){
                nodo->board[x][y] = nodo->board[1][1];
                nodo->board[1][1] = 0;
            }else{
                nodo->board[x][y] = nodo->board[2][2];
                nodo->board[2][2] = 0;
            }
            
        }
        if(x == 1 && y == 1){
            rnd = rand()%4+1;
            if(rnd == 1){
                nodo->board[x][y] = nodo->board[0][1];
                nodo->board[0][1] = 0;
            }else if(rnd == 2){
                nodo->board[x][y] = nodo->board[1][0];
                nodo->board[1][0] = 0;
            }else if(rnd == 3){
                nodo->board[x][y] = nodo->board[2][1];
                nodo->board[2][1] = 0;
            }else{
                nodo->board[x][y] = nodo->board[1][2];
                nodo->board[1][2] = 0;
            }
            
        }
    
    }
}

void isSolution(Puzzle *nodo){
    if(nodo->board[0][0] == 1 && nodo->board[0][1] == 2 && nodo->board[0][2] == 3 && nodo->board[1][0] == 4 && nodo->board[1][1] == 5 && nodo->board[1][2] == 6 && nodo->board[2][0] == 7 && nodo->board[2][1] == 8 ){
        print(nodo);
        exit(1);
    }
}
void print(Puzzle* nodo){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nodo->board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int h(Puzzle *nodo){
    int soma=0,x=1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(nodo->board[i][j] != x){
                soma += nodo->board[i][j];
            }
            x++;
        }
    }
    return soma;
}
int h2(Puzzle *nodo){
    int manhattanDistancia = 0;
    for (int x = 0; x < 3; x++) 
        for (int y = 0; y < 3; y++) { 
            int value = nodo->board[x][y]; 
            if (value != 0) { // Manhattan Distancia
                int targetX = (value - 1) / 3; 
                int targetY = (value - 1) % 3; 
                int dx = x - targetX; 
                int dy = y - targetY; 
                manhattanDistancia += abs(dx) + abs(dy); 
            } 
        }
    return manhattanDistancia;  
}
void copy(Puzzle* origin, Puzzle* destiny){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            destiny->board[i][j] = origin->board[i][j];
        }
    }

}
void Astar(Puzzle start){    
    vector<Puzzle*> opens;
    opens.push_back(&start);
    Puzzle *best , auxPuzzle;
    int f = 9999, aux =0, indice,x,y,xf = 3,yf = 3;
    bool found = false;
    while(true){
        xf = 3,yf = 3,f = 9999, y = 3, x =3; // "zera"
        if(opens.empty()){          
            exit(1);
        }else{
            for (int i = 0; i < opens.size(); i++) {
                aux = h2(opens[i]);
                if(aux < f){
                    f = 0+aux; // f(n) = g(n)+h(n)
                    best = opens[i];
                    indice = i;
                }
            }        
            isSolution(best);
            opens.erase(opens.begin()+indice);
            
            found = false;
            // Encontra a posição do 0 no melhor nodo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if(best->board[i][j] == 0){  
                        x = i;
                        y = j;
                        found = true;
                        break;
                    }
                }
                if(found){
                    break;
                }
            }
            
            found = false;
            if(best->father != NULL){
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if(best->father->board[i][j] == 0){  
                            xf = i;
                            yf = j;
                            found = true;
                            break;
                        }
                    }
                    if(found){
                        break;
                    }
                }
            }
                
            best->one = (puzzle*)malloc(sizeof(puzzle));
            copy(best,best->one);
               
            if(x == 0 && y == 0){               
                if(xf == 0 && yf == 1){
                    best->one->board[x][y] = best->board[1][0];
                    best->one->board[1][0] = 0;              
                }else if(xf == 1 && yf == 0){
                    best->one->board[x][y] = best->board[0][1];
                    best->one->board[0][1] = 0;                  
                }
                opens.push_back(best->one);//retirar                              
            }else if(x == 0 && y == 1){
                best->two = (puzzle*)malloc(sizeof(puzzle));
                copy(best,best->two);
                if(xf == 0 && yf == 0){
                    best->one->board[x][y] = best->board[0][2];
                    best->one->board[0][2] = 0;
                    best->two->board[x][y] = best->board[1][1];
                    best->two->board[1][1] = 0;                   
                }else if(xf == 0 && yf == 2){
                    best->one->board[x][y] = best->board[0][0];
                    best->one->board[0][0] = 0;
                    best->two->board[x][y] = best->board[1][1];
                    best->two->board[1][1] = 0;                    
                }else if(xf == 1 && yf == 1){
                    best->one->board[x][y] = best->board[0][0];
                    best->one->board[0][0] = 0;
                    best->two->board[x][y] = best->board[0][2];
                    best->two->board[0][2] = 0;
                    
                }
                opens.push_back(best->one);
                opens.push_back(best->two);                            
                best->two->father = best;
            }else if(x == 0 && y == 2){             
                if(xf == 0 && yf == 1){
                    best->one->board[x][y] = best->board[1][2];
                    best->one->board[1][2] = 0;                   
                }else if(xf == 1 && yf == 2){
                    best->one->board[x][y] = best->board[0][1];
                    best->one->board[0][1] = 0;                   
                }
                opens.push_back(best->one);                   
            }else if(x == 1 && y == 0){
                best->two = (puzzle*)malloc(sizeof(puzzle));
                copy(best,best->two);
         
                if(xf == 0 && yf == 0){
                    best->one->board[x][y] = best->board[1][1];
                    best->one->board[1][1] = 0;
                    best->two->board[x][y] = best->board[2][0];
                    best->two->board[2][0] = 0;                               
                }else if(xf == 2 && yf == 0){
                    best->one->board[x][y] = best->board[0][0];
                    best->one->board[0][0] = 0;
                    best->two->board[x][y] = best->board[1][1];
                    best->two->board[1][1] = 0;                   
                }else if(xf == 1 && yf == 1){
                    best->one->board[x][y] = best->board[0][0];
                    best->one->board[0][0] = 0;
                    best->two->board[x][y] = best->board[2][0];
                    best->two->board[2][0] = 0;                    
                }
                opens.push_back(best->one);
                opens.push_back(best->two);
                
                best->two->father = best;              
            }else if(x == 1 && y == 1){
               best->two = (puzzle*)malloc(sizeof(puzzle));
               best->three = (puzzle*)malloc(sizeof(puzzle));
               copy(best,best->two);
               copy(best,best->three);                      
               if(xf == 0 && yf == 1){
                    best->one->board[x][y] = best->board[1][0];
                    best->one->board[1][0] = 0;
                    best->two->board[x][y] = best->board[2][1];
                    best->two->board[2][1] = 0;
                    best->three->board[x][y] = best->board[1][2];
                    best->three->board[1][2] = 0;
                    
               }else if(xf == 1 && yf == 2){
                    best->one->board[x][y] = best->board[1][0];
                    best->one->board[1][0] = 0;
                    best->two->board[x][y] = best->board[2][1];
                    best->two->board[2][1] = 0;
                    best->three->board[x][y] = best->board[0][1];
                    best->three->board[0][1] = 0;
                    
               }else if(xf == 1 && yf == 0){
                    best->one->board[x][y] = best->board[2][1];
                    best->one->board[2][1] = 0;
                    best->two->board[x][y] = best->board[1][2];
                    best->two->board[1][2] = 0;
                    best->three->board[x][y] = best->board[0][1];
                    best->three->board[0][1] = 0;
                    
               }else if(xf == 2 && yf == 1){
                    best->one->board[x][y] = best->board[1][0];
                    best->one->board[1][0] = 0;
                    best->two->board[x][y] = best->board[1][2];
                    best->two->board[1][2] = 0;
                    best->three->board[x][y] = best->board[0][1];
                    best->three->board[0][1] = 0;                
               }
               opens.push_back(best->one);
               opens.push_back(best->two);
               opens.push_back(best->three);
               
               best->two->father = best->three->father = best;
            }else if(x == 1 && y == 2){  
                best->two = (puzzle*)malloc(sizeof(puzzle));
                copy(best,best->two);
         
                if(xf == 1 && yf == 1){
                   best->one->board[x][y] = best->board[0][2];
                   best->one->board[0][2] = 0; 
                   best->two->board[x][y] = best->board[2][2];
                   best->two->board[2][2] = 0;   
                }else if(xf == 0 && yf == 2){
                    best->one->board[x][y] = best->board[1][1];
                    best->one->board[1][1] = 0;
                    best->two->board[x][y] = best->board[2][2];
                    best->two->board[2][2] = 0;                  
                }else if(xf == 2 && yf == 2){
                    best->one->board[x][y] = best->board[1][1];
                    best->one->board[1][1] = 0;
                    best->two->board[x][y] = best->board[0][2];
                    best->two->board[0][2] = 0; 
                    
                }             
                opens.push_back(best->one);
                opens.push_back(best->two); 
                delete(best->three);
                best->two->father = best;
            }else if(x == 2 && y == 0){              
                if(xf == 1 && yf == 0){
                    best->one->board[x][y] = best->board[2][1];
                    best->one->board[2][1] = 0;                    
                }else if(xf == 2 && yf == 1){
                    best->one->board[x][y] = best->board[1][0];
                    best->one->board[1][0] = 0;
                    delete(best->two);
                }
                opens.push_back(best->one);                     
            }else if(x == 2 && y == 1){
                best->two = (puzzle*)malloc(sizeof(puzzle));
                copy(best,best->two);
         
                if(xf == 2 && yf == 0){
                    best->one->board[x][y] = best->board[1][1];
                    best->one->board[1][1] = 0;
                    best->two->board[x][y] = best->board[2][2];
                    best->two->board[2][2] = 0;             
                }else if(xf == 1 && yf == 1){
                    best->one->board[x][y] = best->board[2][0];
                    best->one->board[2][0] = 0;
                    best->two->board[x][y] = best->board[2][2];
                    best->two->board[2][2] = 0;                    
                }else if(xf == 2 && yf == 2){
                    best->one->board[x][y] = best->board[1][1];
                    best->one->board[1][1] = 0;
                    best->two->board[x][y] = best->board[2][0];
                    best->two->board[2][0] = 0;                 
                }         
                opens.push_back(best->one);
                opens.push_back(best->two);             
                best->two->father = best;
            }else if(x == 2 && y == 2){               
                if(xf == 2 && yf == 1){                    
                    best->one->board[x][y] = best->board[1][2];
                    best->one->board[1][2] = 0;  
                    
                }else if(xf == 1 && yf == 2){
                    best->one->board[x][y] = best->board[2][1];
                    best->one->board[2][1] = 0;   
       
                }
                opens.push_back(best->one);             
            }       
            best->one->father = best;
        }       
    }
}


int main(int argc, char** argv) {
    Puzzle* nodoInicial = (puzzle*)malloc(sizeof(puzzle));
    int x=1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            nodoInicial->board[i][j] = x;
            x++;
        }
    }
    nodoInicial->board[2][2] = 0;   
    shuffle(nodoInicial); 
    print(nodoInicial);
    
    Puzzle start;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            start.board[i][j] = nodoInicial->board[i][j] ;
            x++;
        }
    }
    Astar(start);
    return 0;
}