#include "settings_common_before.inc"
#include "settings_highres_normal.inc"
#include "settings_common_after.inc"
#include "l3p_terrain_hills_edges_colors.pov"
#declare Tree = cylinder {0, 1, 0.1}

// (1) -------------------------------------------------------------------------------
// Based on code by Kirk Andrews (LandscapeTutorial.pov)
// =====================================================
//  This is a simple Proximity Function.
//  To be used for many things in a landscape scene.
#declare r         = seed(10);
#declare Radius    = 81920;
#declare WriteTrees = true;
#declare NumTrees  = 1000;
#declare Landscape = terrain__hills__edges__colors_dot_ldr;	//fill in here the correct name

#declare ProxF =
function {
  pigment {
    average
    pigment_map { 
      #local i = 0;
      #while (i < 50)
        [   
          // The object pattern, using the terrain.
          object {            
            object {Landscape
              translate <rand(r)-0.5, rand(r)-0.5, rand(r)-0.5>*rand(r)
            }
            color rgb 0,      // outside object
            color rgb 1       // inside object  
          } 
        ]                                                
        #local i = i+1;
      #end	//while
    }	//pigment_map
  }	//pigment
}	//function

#declare ObjF =
function {
  pattern {
    bumps
    turbulence 0.1
    scale 1.0 			//scale up or down according to need
  }
}

// An object inside which the trees exist (added by TdG):
#declare SpherePos = Camera_Location;
#declare YAxis = Camera_LookAt - Camera_Location;

#declare ExistenceSphere =
#difference {
  sphere {0, Radius}
  plane {y, 0}
  pigment {rgbt 1}
  Point_At_Trans(YAxis)
  translate SpherePos
}

// (2) -------------------------------------------------------------------------------
// writing random locations to file:
#declare i = 0; 

#if (WriteTrees)
  #debug "   writing tree locations...\n"
  #fopen TreeLocs "TreeLocs.inc" write

  #declare TS = 5000;	                      // TerrainScale (scope of the heightfield or area around the origin) 
  #declare MaxY = max_extent(Landscape).y;  // Find the highest altitude of the terrain

  #while (i <= NumTrees) 
    #declare Norm = <0, 0, 0>;
    
    // Pick a random place within the scope of the terrain
    #declare Start = <(rand(r)-0.5)*2*TS, 50000, (rand(r)-0.5)*2*TS>;
    
    // Find out where that random spot is on the ground
    //                    target     spot   direction  normal
    #declare Pos = trace (Landscape, Start, -y,        Norm );   
    
    // We've got our random spot, but should an object be there?                                                       
    #declare Visible = IsObjectVisible(Pos)
    #if (Visible & inside(ExistenceSphere,Pos))
      #local Shade = eval_pigment(Map,Pos);
      #if (
         Shade.red = 1
         //Pos.y >= 16.0
         //& Pos.y > .01*MaxY                           //  Altitude controls:  Minimum
         //&Pos.y < (.5+rand(r)*.4)*MaxY                //     "         "   :  Maximum, with a little feathering
         & vdot(Norm, y) > 0.95                          //  Limit the slope on which the tree grows(steep 0 <flat 1).  vdot is a dot product function.
         & ObjF(Pos.x,Pos.y,Pos.z) < 0.5+rand(r)*.1   //  I use a function to gather trees together, while some bare spots remain.  The rand() helps feather the edges. 
         & ProxF(Pos.x,Pos.y,Pos.z).red > 0.45        //  Here's that proximty function again.  Trees shouldn't grow on the peaks of rocky ridges.  
        )
    
        //Writing the last line in the file:
        #if (i = NumTrees)
          #write (TreeLocs,Pos,", ",Norm,"\n")
        #else
          #write (TreeLocs,Pos,", ",Norm,",\n")
        #end

        // Just a little code to let me know how the posing is coming:
        #if (mod(i,NumTrees/100) = 0)    
          #debug concat("   Trees: ", str(i,5,0), "\n") 
        #end 
     
        #local i = i + 1;  // The counter only ticks if an object is actually posed. 
      #end	//of if conditions
    #end	//of if Visible & ExistenceSphere
  #end	//of while loop

  #fclose TreeLocs

#end	//of Write

// (3) -------------------------------------------------------------------------------
// Reading tree locations:
#debug "   reading tree locations...\n"

//Exact Sun position in the scene file for casting optimal shadows on the billboard tree:
#declare Shadow  = vrotate(SunPosition, <Sun_alt, Sun_azm, 0.0>);

#declare Billboard0 =
plane {
  z, 0
  translate  1.0*y
  material {
    texture {      
      pigment {
        image_map {png "CL12m_bill_var" gamma 1 once}
      }      
      finish {
        diffuse 0.9
        specular 0.7
        roughness 0.002
        conserve_energy
        emission 0.1
      }      
    }
    scale <2.0, 2.0, 1.0>
    translate <-1.00, 0.00, 0.00>
  }
  hollow
  clipped_by {box {<-1, -1, -1>, <1, 2, 1>}}
}

#declare Billboard_Tree0 =
object {Billboard0
  scale 4
}

#declare Billboard1 =
plane {
  z, 0
  translate  1.0*y
  material {
    texture {      
      pigment {
        image_map {png "TR03a_bill_var" gamma 1 once}
      }      
      finish {
        diffuse 0.9
        specular 0.7
        roughness 0.002
        conserve_energy
        emission 0.1
      }      
    }
    scale <2.0, 2.0, 1.0>
    translate <-1.00, 0.00, 0.00>
  }
  hollow
  clipped_by {box {<-1, -1, -1>, <1, 2, 1>}}
}

#declare Billboard_Tree1 =
object {Billboard1
  scale 4
}

//-------------------------------------------------------------------------------
  
// If you don't have a tree file, this'll do for now:
#declare WOOD =
cone {
  1*y,  0.0,
  -1*y, 0.1
  // open 
  texture {
    pigment {srgb <0.3, 0.2, 0.1>}
  }
}

#declare FOLIAGE =
cone {
  1*y, 0.0,
  0.2*y, 0.4
  //texture {
  //  pigment {rgb <0.2, 0.5, 0.1>}
  //}
}
  
#declare TREE =
union {
  object {WOOD}
  object {FOLIAGE}
}

#declare Simple = off;

//-------------------------------------------------------------------------------
//Choosing the trees:
#local Probability0 = 0.4;
#local Probability1 = 0.5;
#local Probability2 = 0.8;
#local FProb        = seed(596043);

#fopen TreeLocs "TreeLocs.inc" read
#declare Count = 0;

union {
  #while (defined(TreeLocs))
    #read (TreeLocs, Pos, Norm)
    
    #declare Count = Count + 1;
    // Just a little code to let me know how the posing is coming:
    #if (mod(Count,NumTrees/10) = 0)    
      #debug concat("   Trees: ", str(Count,5,0), "\n") 
    #end 
     
    #if (Simple)
      // POV-Tree separates the resulting tree into "WOOD" and "FOLIAGE".  I like to plant some occasional dead trees,
      // without the foliage.  
      object {
        #if (rand(r) > .9)
          WOOD
        #else
          TREE
          // If you go into the generated POV-Tree .inc file, you can delete the texture attribution on the FOLIAGE mesh,
          // allowing to add it here with some variation from tree to tree.
          texture {  
            pigment {srgb <0.2+rand(r)*0.05, 0.5+rand(r)*0.15, 0.1>}
          } 
        #end
      } 
    #else
      #local TreeType0 = Prob(Probability0, FProb);
      #local Rot = Prob(Probability1, FProb);
      #if (TreeType0)
        #local Tree = object {Billboard_Tree0}
        #if (Rot) #local Tree = object {Tree rotate 180*y} #end
      #else
        #local Tree = object {Billboard_Tree1}
        #if (Rot) #local Tree = object {Tree rotate 180*y} #end
      #end
    #end
    object {Tree
      // The following tranformations are all about increasing the perceived variety of objects/trees in the scene:        
      //translate -rand(r)*0.3*y                                             // This trick will work as long as your camera isn't too close. It adds to the perceived variety of trees.
      scale 1                                                            // POV-Trees are 1 unit tall.  You'll have to figure out how tall your trees should be in your scene.
      //scale <0.5+rand(r), 0.5+ObjF(Pos.x,Pos.y,Pos.z)*2, 0.5+rand(r)>     // scale variation 1
      //scale <1, 0.5+ObjF(Pos.x,Pos.y,Pos.z)*2, 1>                         // scale variation 2
      //scale 0.3 + ObjF(Pos.x,Pos.y,Pos.z)*2                               // scale variation 3
      //#if (rand(r) > .5) scale <-1, 1, 1> #end                            // Flip some trees 
      //scale <1, 1+ProxF(Pos.x,Pos.y,Pos.z).red, 1>                        // Trees in ditches should be taller. The ProxF function should provide a decent approximation.
      //rotate rand(r)*2*x
      //rotate rand(r)*360*y
      //Reorient_Trans(y, Norm)
      
      //the first version is the tree billboard, without shadow, but oriented towards the camera
      Reorient_Trans(-z, <CamLoc.x, 0.0, CamLoc.z>)
      translate Pos
      no_shadow
    }
    //the second version is the tree billboard, without image, casting its shadow full from the Sun's location
    object {Tree
      scale 1
      Reorient_Trans(-z, <Shadow.x, 0.0, Shadow.z>)
      translate Pos
      no_image
    }
             
  #end	//of while defined

}	//end of union

#debug "Done.\n\n"