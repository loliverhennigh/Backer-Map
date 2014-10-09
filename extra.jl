
using Winston

function create_ordered(size)
	vec = fill(0.0, size);
	for i=1:size
		vec[i] = i;
	end 
	return vec
end

function plot_boundry_per()
	y = readdlm("experiment_boundry_a_no_pert.txt")
	y = reshape(y, size(y,1))
	x = create_ordered(size(y,1));
	plot(x,y);
	hold();
	yy = readdlm("experiment_boundry_a_yes_pert.txt")
	yy = reshape(yy, size(yy,1))
	plot(x,yy);
end



