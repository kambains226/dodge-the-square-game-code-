#include "raylib.h"
#include <iostream>

echo "# dodge-the-square-game-code-" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/kambains226/dodge-the-square-game-code-.git
git push -u origin main

int main() {
     
   
    //window dimensions 
     int width{800};
     int height{450};

    InitWindow (width,height  , "kams screen");
   
   //circle 
   int circle_x{200};
   int circle_y{200};
   int circle_radius{25};
   //circle edges 
   int l_circle_x{circle_x - circle_radius};
   int r_circle_x{circle_x + circle_radius};
   int u_circle_y{circle_y - circle_radius};
   int b_circle_y{circle_y + circle_radius};
   //Rectangle 
   int rec_x{400};
   int rec_y{0};
   int axe_length{50};
   //axe edges

   int l_axe_x{rec_x};
   int r_axe_x{rec_x+axe_length};
   int u_axe_y{rec_y};
   int b_axe_y{rec_y+axe_length};

   int direction {15};
   //collisions detection 
   bool collision_with_axe = 
                    (b_axe_y >=  u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

   int score {0}; 
   SetTargetFPS(60);
   while (WindowShouldClose()==false ) {
    BeginDrawing();
    ClearBackground(WHITE);
      
     
    
    if (collision_with_axe){
      DrawText("Game over!" ,150 , 100 ,100 ,PINK );
      DrawText(TextFormat("YOU GOT A SCORE OF %i" , score),220,100,30,BLACK ); 
    }
      else {
          
      // game logic starts 

      //update the edges

      int l_circle_x{circle_x - circle_radius};
      int r_circle_x{circle_x + circle_radius};
      int u_circle_y{circle_y - circle_radius};
      int b_circle_y{circle_y + circle_radius};

      int l_axe_x{rec_x};
      int r_axe_x{rec_x+axe_length};
      int u_axe_y{rec_y};
      int b_axe_y{rec_y+axe_length};

      //update collision with ace

      collision_with_axe = 
                    (b_axe_y >=  u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

      DrawCircle(circle_x, circle_y ,circle_radius,BLUE);
      //score


      
      if (circle_x == width/2 || circle_y == height/2)  {
        score += 1 ;

      }
      else {
        score= score;
      }
      
      DrawRectangle(rec_x,rec_y,axe_length,axe_length ,RED);
      //axe movement
      rec_y += direction;
      if (rec_y > height|| rec_y < 0 ) {
        direction = -direction;
      
      }

      //movement of circle 
      if (IsKeyDown(KEY_D)&& circle_x <width )
      {
        circle_x +=  10;
      }
      
      if (IsKeyDown(KEY_A)&& circle_x > 0 )
      {
        circle_x -= 10;
      }

      if (IsKeyDown(KEY_W)&& circle_y > 0 ){

      circle_y -=10;
    
      }
      if (IsKeyDown(KEY_S)&& circle_y < height )
      {
        circle_y += 10; 
      }
      //draws score text 
      }

      DrawText(TextFormat("Score: %i",score),50,400,10,BLACK);
      
      
     
      //game logic ends 
      
  
      EndDrawing();
    
   }

  }  
