#include <iostream>
#include <vector>
#include <map>

using namespace std;

int max_attack, block;

vector<int> tower_list;
vector<int> monster_pos;
vector<int> monster_hp;
int range;

void tower_attack(int ind_tower, int ind_monster, 
                  int shot, int left, int right, bool lastShot){
    // decrease the feasible monster hp by 1
    bool haveAttack = false;
    if (monster_pos[ind_monster] && monster_hp[ind_monster]>0){
        monster_hp[ind_monster]--;
        shot += 1;
        haveAttack = true;
    }
    //last lower and last monster in ranges => max return
    if(ind_tower == tower_list.size()-1 && ind_monster == right) {
        max_attack = max(max_attack, shot);
        if(haveAttack) monster_hp[ind_monster]++;  //undo the shot
        return;
    }


}

void attack(int ind_tower, int ind_monster){
    int shot = 0;
    int tower_pos = tower_list[ind_tower];
    int left = max(0, tower_pos - range);
    int right = min(block - 1, tower_pos + range);
    bool lastShot = false;

    for (int i=ind_tower; i<tower_list.size(); i++){ //for every tower in list
        if (monster_pos[ind_monster] == -1) continue;
        monster_hp[ind_monster]--;
        shot += 1;
    }

}


int main(){
    max_attack = 0;

    int num_mon, num_tower, range, ele;
    cin >> block >> num_mon >> num_tower >> range;
    monster_hp.assign(num_mon, 0);     //
    monster_pos.assign(num_mon, -1);   //
    vector<int> tower_list(num_tower);       //
    //vector<int> tower_list()

    vector<int> monster_min_pos(num_mon);
    //input position of each monstsers for # num_mon
    // monster_pos = {0,1} // exist in the block?
    for (int i=0; i<num_mon; i++){
        cin >> ele;
        --ele;
        monster_pos[ele] = 1;
        monster_min_pos[i] = ele;
    }
    //input monster HP
    //hp of monster in exist block
    for (int i=0; i<num_mon; i++){
        cin >> ele;
        monster_hp[monster_min_pos[i]-1] = ele;
    }
    // input tower position
    // sorted list of towers (not using block)
    for (int i=0; i<num_tower; i++){
        cin >> ele;
        --ele;
        tower_list[i] = ele;
    }
    sort(tower_list.begin(), tower_list.end());

    attack();    //************************

    cout << max_attack;
}