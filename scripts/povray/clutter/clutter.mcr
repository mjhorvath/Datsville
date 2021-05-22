//-----clutter macro---------------
//-----Author: Jonathan Rafael Ghiglia
//-----Date: 5th July 2001 14.30 first version
//-----12th July 2001 last version
//-----12th September 2001- POV 3.5 update
// Updated: 2021 Michael Horvath
// See: povray.advanced-users, "Need a script to randomly scatter objects vertically", Tue, 20 Apr 2021 00:02:48 -0400


#macro Interpolate(T,T1,T2,P1,P2)
//	(P1+(T1+T/(T2-T1))*(P2-P1))
	(P1+(T-T1)/(T2-T1)*(P2-P1))
#end
 

#macro clutter
	(
		ob_ar,       // objects array
		ob_rel_ar,   // objects related array
		obstacle_ar, // obstacle array
		x_lim,       // x limit
		z_lim,       // z limit
		p,           // probability array
		map,         // probability map array
		do_tex,      // switch texture interpolation on/off
		tex_ar,      // textures array
		map_tex,     // map for textures interpolation
		land,        // environment you want to place the objects on
		rotation,    // switch normal orientation on/off
		max_y_rot,   // max random rotation around y axis
		RS,          // random seed
		file_option, // 0 do not save array file, 1 write array file, 2 read array file
		file_name    // name of the file you want to write or read
	)
	#local ob = dimension_size(ob_ar,1);
	#local i = 0;
	#local num_tot = 0;
	#while (i < ob)
		#local step_tot = ob_rel_ar[i][0];
		#local num_tot = num_tot + step_tot;
		#local i = i + 1;
	#end  
	#if (file_option != 2)
	#local pos = array[num_tot][2];
	#local alt = array[num_tot];
	#if (rotation)
		#local norm = array[num_tot];
	#end   
	#local i = 0;
	#local num = 0;
	#while (i < ob)
		#undef fn
		#declare fn = function {pigment {map[i]}}
		#local j = 0;
		#while (j < ob_rel_ar[i][0])  
			#local temp_pos = <rand(RS)*x_lim,0,rand(RS)*z_lim>;
			//-------check the probability
			#local _error = 0;
			#local eval = (fn(temp_pos.x,temp_pos.y,temp_pos.z));
			#local _eval = vlength(<eval.x,eval.y,eval.z>);
			#local prob = Interpolate(_eval,0,sqrt(3),p[i][0],p[i][1]);
			#if (prob != 0) 
				#local _alea = ceil(rand(RS)*(1/prob));
				#if (_alea != 1)
					#local _error = 1;
				#end
			#else
				#local _error = 1;
			#end
			//-------check the obstacles
			#if (!_error)
				#local _i = 0;
				#while (_i < dimension_size(obstacle_ar,1))
					#if (vlength(temp_pos-obstacle_ar[_i][0])<(vlength (obstacle_ar[_i][1])+ob_rel_ar[i][1]))
						#local _er = 1;
					#else
						#local _er = 0;
					#end
					#local _error = _error + _er;
					#local _i = _i + 1;
				#end
			#end
			//-------check the coordinates-------
			#if (!_error)
				#local _i = 0;
				#while (_i < num)
					#if (vlength (temp_pos-pos[_i][0])<(vlength (pos[_i][1])+ob_rel_ar[i][1])) #local _er=1; #else #local _er=0; #end
					#local _error = _error+_er;
					#local _i = _i + 1;
				#end
			#end
			//----------
			#if (!_error)
				#local _norm1 = <0,0,0>; 
				#local _alt = vdot(y,trace(land, temp_pos+10000*y,-y,_norm1));  // check the altitude
				#local pos[num][0] = temp_pos; 
				#local pos[num][1] = ob_rel_ar[i][1] * <1,0,0>;
				#local alt[num] = _alt * <0,1,0>; 
				#if (rotation)
					#local _norm2 = <0,0,0>;
					#local nothing = vdot(y,trace(land, temp_pos+10000*y+vlength(ob_rel_ar[i][1])*x,-y,_norm2));
					#local _norm3 = <0,0,0>;
					#local nothing = vdot(y,trace(land, temp_pos+10000*y-vlength(ob_rel_ar[i][1])*x,-y,_norm3));
					#local _norm4 = <0,0,0>;
					#local nothing = vdot(y,trace(land, temp_pos+10000*y+vlength(ob_rel_ar[i][1])*z,-y,_norm4));
					#local _norm5 = <0,0,0>;
					#local nothing = vdot(y,trace(land, temp_pos+10000*y-vlength(ob_rel_ar[i][1])*z,-y,_norm5));
					#local norm[num] = (_norm1+_norm2+_norm3+_norm4+_norm5)/5; 
					#if (!vlength(norm[num])) 
						#error "error in normal calculation!\n"
					#end
				#end 
				#local num = num + 1;
				#debug concat("parsed ",str(num,0,0)," positions\n")
				#local j = j + 1;
			#end
		#end
		#local i = i + 1;
	#end
	//----------else load file
	#else
		#include file_name
	#end
	//---------check texture
	#if (do_tex)
		#local _tex = array[num_tot];
		#local mt = 0;
		#local to = 0;
		#while (mt < ob)
			#undef fn2
			#declare fn2 = function {pigment {map_tex[mt]}}
			#local ind = 0;
			#while (ind < ob_rel_ar[mt][0])
				#local eval_tex = fn2(pos[to][0].x,pos[to][0].y,pos[to][0].z);
				#local _eval_tex = vlength(<eval_tex.x,eval_tex.y,eval_tex.z>);
				#local _tex[to] = Interpolate(_eval_tex,0,sqrt(3),0,10000);
				#local to = to + 1;
				#local ind = ind + 1;
			#end
			#local mt = mt + 1;
		#end
	#end
	//---------save arrays in a file
	#if (file_option = 1)
		#debug "\nWriting array file\n"
		#fopen arr_file file_name write  
		#write (arr_file,"//------Clutter arrays file------\n") 
		//---------saving pos array
		#write (arr_file,"\n#declare pos=array[",num_tot,"][2]\n")
		#local _i = 0;
		#while (_i < num_tot)
			#write (arr_file,"#declare pos[",_i,"][0]=",pos[_i][0],";\n#declare pos[",_i,"][1]=",pos[_i][1],";\n") 
			#local _i = _i + 1;
		#end
		//--------saving alt array
		#write (arr_file,"\n#declare alt=array[",num_tot,"]\n")
		#local _i = 0;
		#while (_i < num_tot)
			#write (arr_file,"#declare alt[",_i,"]=",alt[_i],";\n")
			#local _i = _i + 1;
		#end
		//--------saving normal array
		#if (rotation)
			#write (arr_file,"\n#declare norm=array[",num_tot,"]\n")
			#local _i = 0;
			#while (_i < num_tot)
				#write (arr_file,"#declare norm[",_i,"]=",norm[_i],";\n")
				#local _i = _i + 1;
			#end
		#end   
		//--------end of saving
		#fclose arr_file
	#end
	//-------now place the objects----------
	union
	{
		#local _n = 0;
		#local _p = 0;
		#while (_n < ob)
			#local _sub = 0;
			#while (_sub < ob_rel_ar[_n][0])
				object
				{
					ob_ar[_n] 
					#if (do_tex)
						texture
						{
							pigment_pattern {function {max (0,min(1,x))} scale 10000}
							texture_map {[0 tex_ar[_n][1]][1 tex_ar[_n][0]]}
							translate -_tex[_p]*x
						}
					#end
					rotate (max_y_rot*rand(RS)-max_y_rot * rand(RS)) * y 
					#if (rotation)
						rotate <degrees(atan2(norm[_p].z,norm[_p].y)),0,-degrees(atan2(norm[_p].x,norm[_p].y))>
					#end
					translate (pos[_p][0] + alt[_p])
				}
				#local _p = _p + 1;
				#local _sub = _sub + 1;
			#end
			#local _n = _n + 1;
		#end
	}
	//-----end of macro----
#end
