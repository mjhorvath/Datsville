//-----clutter macro---------------
//-----Author: Jonathan Rafael Ghiglia
//-----Date: 5th July 2001 14.30 first version
//-----12th July 2001 last version
//-----12th September 2001- POV 3.5 update
// Updated: 2021 Michael Horvath
// See: povray.advanced-users, "Need a script to randomly scatter objects vertically", 20 Apr 2021 00:02:48 -0400
// See: povray.advanced-users, "clutter.mcr and trace()", 17 May 2021 01:12:14 -0400
// To do: use dictionaries instead of multiple arrays
// To do: use map for transforms interpolation


#macro Interpolate(T,T1,T2,P1,P2)
	(P1+(T-T1)/(T2-T1)*(P2-P1))
#end
 
#macro LDRound(number, base, offs)
	floor(number / base) * base + offs
#end

#macro Round(number, base)
	floor(number / base + 0.5) * base
#end


#macro clutter
	(
		obj_obj_ar,     // object array
		obj_num_ar,     // object numbers array
		obj_rad_ar,     // object radii array
		obj_nam_ar,     // object names array
		obstacle_ar,    // obstacle array
		x_lim,          // x limit
		z_lim,          // z limit
		xyz_round,      // pos rounding amounts
		xyz_offset,     // pos rounding offsets
		obj_p_ar,       // probabilities array
		obj_pmap_ar,    // probabilities interpolation map array
		do_tex,         // switch texture interpolation on/off
		obj_t_ar,       // textures array
		obj_tmap_ar,    // textures interpolation map array
		land,           // environment you want to place the objects on
		rotation,       // switch normal orientation on/off
		max_y_rot,      // max random rotation around y axis
		rnd_y_rot,		// rotation rounding amount around y axis
		RS,             // random seed
		file_option,    // 0 do not write array file, 1 write array file, 2 read array file, 3 write array file only
		file_name       // name of the file you want to write or read
	)
	#local ob = dimension_size(obj_obj_ar,1);
	#local i = 0;
	#local num_tot = 0;
	#while (i < ob)
		#local step_tot = obj_num_ar[i];
		#local num_tot = num_tot + step_tot;
		#local i = i + 1;
	#end
	//---------generate new data
	#if (file_option != 2)
		#debug "\ngenerating data\n"
		#local pos = array[num_tot];
		#local rad = array[num_tot];
		#local alt = array[num_tot];
		#local rnd = array[num_tot];
		#if (rotation)
			#local norm = array[num_tot];
		#end   
		#local i = 0;
		#local num = 0;
		#while (i < ob)
			#undef fn
			#declare fn = function {pigment {obj_pmap_ar[i]}}
			#local j = 0;
			#while (j < obj_num_ar[i])
				#local temp_pos = <LDRound(rand(RS)*x_lim,xyz_round.x,xyz_offset.x),0,LDRound(rand(RS)*z_lim,xyz_round.z,xyz_offset.z)>;
				//-------check the probability
				#local _error = 0;
				#local eval = (fn(temp_pos.x,temp_pos.y,temp_pos.z));
				#local _eval = vlength(<eval.x,eval.y,eval.z>);
				#local prob = Interpolate(_eval,0,sqrt(3),obj_p_ar[i][0],obj_p_ar[i][1]);
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
						#if (vlength(temp_pos-obstacle_ar[_i][0])<(vlength (obstacle_ar[_i][1])+obj_rad_ar[i]))
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
						#if (vlength (temp_pos-pos[_i])<(rad[_i]+obj_rad_ar[i]))
							#local _er=1;
						#else
							#local _er=0;
						#end
						#local _error = _error+_er;
						#local _i = _i + 1;
					#end
				#end
				//----------
				#if (!_error)
					#local _norm1 = <0,0,0>;
					#local _alt = LDRound(vdot(y,trace(land, temp_pos+10000*y,-y,_norm1)),xyz_round.y,xyz_offset.y);  // check the altitude
					#local pos[num] = temp_pos;
					#local rad[num] = obj_rad_ar[i];
					#local alt[num] = _alt * <0,1,0>;
					#local rnd[num] = Round(max_y_rot*rand(RS)-max_y_rot*rand(RS),rnd_y_rot);
					#if (rotation)
						#local _norm2 = <0,0,0>;
						#local nothing = vdot(y,trace(land, temp_pos+10000*y+vlength(obj_rel_ar[i][1])*x,-y,_norm2));
						#local _norm3 = <0,0,0>;
						#local nothing = vdot(y,trace(land, temp_pos+10000*y-vlength(obj_rel_ar[i][1])*x,-y,_norm3));
						#local _norm4 = <0,0,0>;
						#local nothing = vdot(y,trace(land, temp_pos+10000*y+vlength(obj_rel_ar[i][1])*z,-y,_norm4));
						#local _norm5 = <0,0,0>;
						#local nothing = vdot(y,trace(land, temp_pos+10000*y-vlength(obj_rel_ar[i][1])*z,-y,_norm5));
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
	//---------else load data from file
	#else
		#debug "\nloading data from file\n"
		#include file_name
	#end
	#if ((file_option = 1) | (file_option = 3))
		//---------save arrays in a file
		#debug "\nwriting array file\n"
		#fopen arr_file file_name write  
		#write (arr_file,"//------Clutter arrays file------\n")
		//---------saving pos array
		#write (arr_file,"\n#declare pos=array[",num_tot,"]\n")
		#local _i = 0;
		#while (_i < num_tot)
			#write (arr_file,"#declare pos[",_i,"]=",pos[_i],";\n") 
			#local _i = _i + 1;
		#end
		//---------saving rad array
		#write (arr_file,"\n#declare rad=array[",num_tot,"]\n")
		#local _i = 0;
		#while (_i < num_tot)
			#write (arr_file,"#declare rad[",_i,"]=",rad[_i],";\n") 
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
		#fclose arr_file
		//--------end of saving
		//---------save tsv data in a file
		#debug "\nwriting tsv file\n"
		#fopen arr_file "output.txt" write  
		#write (arr_file,"x\ty\tz\trad\trnd\tnam\n") 
		//---------saving coords
		#local _n = 0;
		#local _p = 0;
		#while (_n < ob)
			#local _sub = 0;
			#while (_sub < obj_num_ar[_n])
				#write (arr_file,pos[_p].x,"\t",alt[_p].y,"\t",pos[_p].z,"\t",rad[_p],"\t",rnd[_p],"\t",obj_nam_ar[_n],"\n")
				#local _p = _p + 1;
				#local _sub = _sub + 1;
			#end
			#local _n = _n + 1;
		#end
		#fclose arr_file
		//--------end of saving
	#end
	#if (file_option != 3)
		//---------check texture
		#debug "\nchecking textures\n"
		#if (do_tex)
			#local _tex = array[num_tot];
			#local mt = 0;
			#local to = 0;
			#while (mt < ob)
				#undef fn2
				#declare fn2 = function {pigment {obj_tmap_ar[mt]}}
				#local ind = 0;
				#while (ind < obj_num_ar[mt])
					#local eval_tex = fn2(pos[to].x,pos[to].y,pos[to].z);
					#local _eval_tex = vlength(<eval_tex.x,eval_tex.y,eval_tex.z>);
					#local _tex[to] = Interpolate(_eval_tex,0,sqrt(3),0,10000);
					#local to = to + 1;
					#local ind = ind + 1;
				#end
				#local mt = mt + 1;
			#end
		#end
		//-------now place the objects----------
		#debug "\nplacing objects\n"
		union
		{
			#local _n = 0;
			#local _p = 0;
			#while (_n < ob)
				#local _sub = 0;
				#while (_sub < obj_num_ar[_n])
					object
					{
						obj_obj_ar[_n] 
						#if (do_tex)
							texture
							{
								pigment_pattern {function {max (0,min(1,x))} scale 10000}
								texture_map {[0 obj_t_ar[_n][1]][1 obj_t_ar[_n][0]]}
								translate -_tex[_p]*x
							}
						#end
						rotate rnd[_p] * y
						#if (rotation)
							rotate <degrees(atan2(norm[_p].z,norm[_p].y)),0,-degrees(atan2(norm[_p].x,norm[_p].y))>
						#end
						translate (pos[_p] + alt[_p])
					}
					#local _p = _p + 1;
					#local _sub = _sub + 1;
				#end
				#local _n = _n + 1;
			#end
		}
	#else
		sphere
		{
			0, 1
			hollow
			no_image
			no_shadow
			no_reflection
			no_radiosity
		}
	#end
	//-----end of macro----
#end
