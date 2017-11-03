#include <math.h>
#include <iostream>
#include <vector>
#include <cmath>  

using namespace std;

//a cost function that finds the best lane to be in
int best_lane(int lane,vector<double> left_lane_s,vector<double> left_lane_speed,vector<double> center_lane_s,vector<double> center_lane_speed,vector<double> right_lane_s,vector<double> right_lane_speed){


	//a vector to recive the costs
	vector <double> costs;
	int best_lane;

	//check the size of each incoming lane
	int left_lane_len=left_lane_s.size();
	int center_lane_len=center_lane_s.size();
	int right_lane_len=right_lane_s.size();

	//check left lane
	if(left_lane_len>0){
		//get the distance to the closest car
		double left_closest = *min_element(left_lane_s.begin(), left_lane_s.end());
		//push the cost calc to the cost vector
		costs.push_back(left_closest);

	}
	//else pushback a cost of zero to the vector
	else{
		costs.push_back(5000);
	}

	//check center lane
	if(center_lane_len>0){
		//get the distance to the closest car
		double center_closest = *min_element(center_lane_s.begin(), center_lane_s.end());
		//push the cost calc to the cost vector
		costs.push_back(center_closest);

	}
	//else pushback a cost of zero to the vector
	else{
		costs.push_back(5000);
	}

	//check right lane
	if(right_lane_len>0){
		//get the distance to the closest car
		double right_lane_closest = *min_element(right_lane_s.begin(), right_lane_s.end());
		//push the cost calc to the cost vector
		costs.push_back(right_lane_closest);

	}
	//else pushback a cost of zero to the vector
	else{
		costs.push_back(5000);
	}
	
	//if all lanes are wide open just return the lane the car is in now
	if(costs[0]==0 && costs[1]==0 && costs[2]==0){
		//return lane;
		best_lane=lane;
	}

	//else return the lane with the highest cost (which happens to be the lane with the most open distance)
	else{
		
		double best_cost = *max_element(costs.begin(), costs.end());
		if(costs[0]==best_cost){
			best_lane=0;
		}
		if(costs[1]==best_cost){
			best_lane=1;
		}
		if(costs[2]==best_cost){
			best_lane=2;
		}
		
	}

	//return the lane
	return best_lane;
}