#declare Streets_Number = 19;
#declare Streets_Labels = array[Streets_Number]
{
	"1st St",
	"2nd St",
	"3rd St",
	"3rd St",
	"4th St",
	"4th St",
	"5th St",
	"5th St",
	"6th St",
	"6th St",
	"7th St",
	"7th St",
	"Andersen St",
	"Wilson Circ",
	"Eriksson Pkwy",
	"VanZwieten Blvd",
	"Jessiman Ave",
	"Dennet Ave",
	"Gould Ave"
}
#declare Streets_Angles = array[Streets_Number]
{
	0,	// 1st St
	0,	// 2nd St
	0,	// 3rd St
	0,	// 3rd St
	0,	// 4th St
	0,	// 4th St
	0,	// 5th St
	0,	// 5th St
	0,	// 6th St
	0,	// 6th St
	0,	// 7th St
	0,	// 7th St
	90,	// Andersen St
	90,	// Wilson Circ
	90,	// Eriksson Pkwy
	90,	// VanZwieten Blvd
	90,	// Jessiman Ave
	90,	// Dennet Ave
	90	// Gould Ave
}
#declare Streets_Coords = array[Streets_Number]
{
	<-10.5, 0, -3.5> * 640,	// 1st St
	< -6.5, 0, -3.5> * 640,	// 2nd St
	< -3.5, 0, +1.5> * 640,	// 3rd St
	< -3.5, 0, +7.5> * 640,	// 3rd St
	< -0.5, 0, -3.5> * 640,	// 4th St
	< -0.5, 0, +7.5> * 640,	// 4th St
	< +3.5, 0, -3.5> * 640,	// 5th St
	< +3.5, 0, +7.5> * 640,	// 5th St
	< +6.5, 0, -3.5> * 640,	// 6th St
	< +6.5, 0, +7.5> * 640,	// 6th St
	<+10.5, 0, -3.5> * 640,	// 7th St
	<+10.5, 0, +7.5> * 640,	// 7th St
	< -8.0, 0, +4.5> * 640,	// Andersen St
	<-10.0, 0, +8.5> * 640,	// Wilson Circ
	< -4.0, 0, +9.5> * 640,	// Eriksson Pkwy
	< +4.0, 0, +5.5> * 640,	// VanZwieten Blvd
	< +4.0, 0, +3.5> * 640,	// Jessiman Ave
	< +4.0, 0, -0.5> * 640,	// Dennet Ave
	< +4.0, 0, -6.5> * 640	// Gould Ave
}
