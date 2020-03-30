//
// Created by lica-pc on 3/29/20.
//

#include "funciones.h"
#include <sstream>

string max(vector<P> proposals)
{
    float max = proposals[0].compliance;
    string nombre = proposals[0].name;
    for(auto &proposal : proposals)
    {
        if (max<proposal.compliance)
        {
            max = proposal.compliance;
            nombre = proposal.name;
        }
    }
    return nombre;
}

void RFP(string nums, int contador)
{
    while (getline(cin, nums))
    {
        stringstream esp(nums);
        int n,p;
        esp >> n >> p;
        if (n == 0 && p == 0)
            break;
        else
        {
            contador++;
            vector<P> proposals;
            vector<string> requirements;
            int n_temp = n;
            //getting list of requirements
            do {
                string requirement;
                getline(cin,requirement);
                requirements.push_back(requirement);
            } while (n_temp-- && n_temp!=0);
            int size = requirements.size();
            //getting proposals
            do {
                P proposal;
                getline(cin, proposal.name);
                string d_r_String;
                getline(cin,d_r_String);
                stringstream d_r(d_r_String);
                d_r >> proposal.price >> proposal.cant_req ;
                proposal.compliance = (float) proposal.cant_req/ (float) size;
                //getting proposal's requirements met
                int temp = proposal.cant_req;
                do {
                    string requirement_met;
                    getline(cin,requirement_met);
                    proposal.requirements_met.push_back(requirement_met);
                } while (temp-- && temp!=0);
                proposals.push_back(proposal);
            }while(p-- && p!=0);
            string mayor = max(proposals);
            cout << "RFP #" << contador << endl;
            cout << mayor << endl << endl;
        }
    }
}