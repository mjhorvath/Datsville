#declare in_sphere = sphere
{
	0,1
}

#declare two_sphere = object
{
	in_sphere
	translate x
}

#declare two_sphere = object
{
	two_sphere
	translate y
}

#declare empty = union
{
}
