#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;



int main(){
    int block, num_mon, num_tower, range, ele;
    cin >> block >> num_mon >> num_tower >> range;
    vector<int> tower_list(num_tower);
    vector<int> monster_hp(block, 0);

    vector<int> monster_pos_list(num_mon);
    //input position of each monstsers for # num_mon
    // monster_pos = {0,1} // exist in the block?
    for (int i=0; i<num_mon; i++){
        cin >> ele;
        monster_pos_list[i] = --ele;
    }
    //input monster HP
    //hp of monster in exist block
    for (int i=0; i<num_mon; i++){
        cin >> ele;
        monster_hp[monster_pos_list[i]] += ele;
    }
    // input tower position
    // sorted list of towers (not using block)
    for (int i=0; i<num_tower; i++){
        cin >> ele;
        tower_list[i] = --ele;
    }
    sort(tower_list.begin(), tower_list.end());

    for (int i=0; i<num_tower; i++){
        int current_tower = tower_list[i];
        int start = max(0, current_tower - range);
        int stop  = min(block-1, current_tower + range);
        int max_hp_mon = start;

        for(int ind = start; ind<= stop; ind++){
            if (monster_hp[ind] == 0) continue;
            max_hp_mon = (monster_hp[ind] > monster_hp[max_hp_mon]) ? ind : max_hp_mon;
        }

        if (monster_hp[max_hp_mon] != 0){
            --monster_hp[max_hp_mon];
        }
    }

    long long total_hp=0;

    for (int i=0; i<block; i++){
        total_hp += monster_hp[i];
    }

    cout << total_hp;

}