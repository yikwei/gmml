
#include "../../../includes/Resolver/PdbPreprocessor/pdbpreprocessorchaintermination.hpp"

using namespace std;
using namespace PdbPreprocessorSpace;
using namespace gmml;

//////////////////////////////////////////////////////////
//                       CONSTRUCTOR                    //
//////////////////////////////////////////////////////////
PdbPreprocessorChainTermination::PdbPreprocessorChainTermination() {}

PdbPreprocessorChainTermination::PdbPreprocessorChainTermination(char chain_id, int starting_sequence_number, int ending_sequence_number, char starting_residue_insertion_code, char ending_residue_insertion_code) :
    residue_chain_id_(chain_id), starting_residue_sequence_number_(starting_sequence_number), ending_residue_sequence_number_(ending_sequence_number),
    starting_residue_insertion_code_(starting_residue_insertion_code), ending_residue_insertion_code_(ending_residue_insertion_code)
{
    selected_n_termination_ = (PossibleNChainTermination)2;
    selected_c_termination_ = (PossibleCChainTermination)3;
}

//////////////////////////////////////////////////////////
//                         ACCESSOR                     //
//////////////////////////////////////////////////////////
char PdbPreprocessorChainTermination::GetResidueChainId()
{
    return residue_chain_id_;
}
int PdbPreprocessorChainTermination::GetStartingResidueSequenceNumber()
{
    return starting_residue_sequence_number_;
}
int PdbPreprocessorChainTermination::GetEndingResidueSequenceNumber()
{
    return ending_residue_sequence_number_;
}
PossibleNChainTermination PdbPreprocessorChainTermination::GetSelectedNTermination()
{
    return selected_n_termination_;
}
PossibleCChainTermination PdbPreprocessorChainTermination::GetSelectedCTermination()
{
    return selected_c_termination_;
}
char PdbPreprocessorChainTermination::GetStartingResidueInsertionCode()
{
    return starting_residue_insertion_code_;
}
char PdbPreprocessorChainTermination::GetEndingResidueInsertionCode()
{
    return ending_residue_insertion_code_;
}

string PdbPreprocessorChainTermination::GetStringFormatOfSelectedNTermination()
{
    switch (selected_n_termination_)
    {
        case 1:
            return "ACE";
        case 2:
            return "NH3+";
        default:
            return "";
    }
}

string PdbPreprocessorChainTermination::GetStringFormatOfSelectedCTermination()
{
    switch(selected_c_termination_)
    {
        case 1:
            return "NHE";
        case 2:
            return "NME";
        case 3:
            return "CO2-";
        default:
            return "";
    }
}

string PdbPreprocessorChainTermination::GetStringFormatOfNTermination(PossibleNChainTermination n_termination)
{
    switch (n_termination)
    {
        case 1:
            return "ACE";
        case 2:
            return "NH3+";
        default:
            return "";
    }
}

string PdbPreprocessorChainTermination::GetStringFormatOfCTermination(PossibleCChainTermination c_termination)
{
    switch(c_termination)
    {
        case 1:
            return "NHE";
        case 2:
            return "NME";
        case 3:
            return "CO2-";
        default:
            return "";
    }
}

vector<string> PdbPreprocessorChainTermination::GetAllPossibleNChainTerminationAsString()
{
    vector<string> all_possible_n_chian_termination_as_string;
    for(int possible_n_chian_termination = COCH3; possible_n_chian_termination != NH3; possible_n_chian_termination++)
        all_possible_n_chian_termination_as_string.push_back(GetStringFormatOfNTermination((PossibleNChainTermination)possible_n_chian_termination));
    return all_possible_n_chian_termination_as_string;
}

vector<string> PdbPreprocessorChainTermination::GetAllPossibleCChainTerminationAsString()
{
    vector<string> all_possible_c_chian_termination_as_string;
    for(int possible_c_chian_termination = NH2; possible_c_chian_termination != CO2; possible_c_chian_termination++)
        all_possible_c_chian_termination_as_string.push_back(GetStringFormatOfCTermination((PossibleCChainTermination)possible_c_chian_termination));
    return all_possible_c_chian_termination_as_string;
}

//////////////////////////////////////////////////////////
//                          MUTATOR                     //
//////////////////////////////////////////////////////////
void PdbPreprocessorChainTermination::SetResidueChainId(char residue_chain_id)
{
    residue_chain_id_ = residue_chain_id;
}
void PdbPreprocessorChainTermination::SetStartingResidueSequenceNumber(int starting_residue_sequence_number)
{
    starting_residue_sequence_number_ = starting_residue_sequence_number;
}
void PdbPreprocessorChainTermination::SetEndingResidueSequenceNumber(int ending_residue_sequence_number)
{
    ending_residue_sequence_number_ = ending_residue_sequence_number;
}
void PdbPreprocessorChainTermination::SetSelectedNTermination(PossibleNChainTermination selected_n_termination)
{
    selected_n_termination_ = selected_n_termination;
}
void PdbPreprocessorChainTermination::SetSelectedCTermination(PossibleCChainTermination selected_c_termination)
{
    selected_c_termination_ = selected_c_termination;
}
void PdbPreprocessorChainTermination::SetStartingResidueInsertionCode(char starting_residue_insertion_code)
{
    starting_residue_insertion_code_ = starting_residue_insertion_code;
}
void PdbPreprocessorChainTermination::SetEndingResidueInsertionCode(char ending_residue_insertion_code)
{
    ending_residue_insertion_code_ = ending_residue_insertion_code;
}

//////////////////////////////////////////////////////////
//                      DISPLAY FUNCTION                //
//////////////////////////////////////////////////////////
void PdbPreprocessorChainTermination::Print(ostream &out)
{
    out << "Chain id " << residue_chain_id_
         << ", Start sequence number: " << starting_residue_sequence_number_
         << ", End sequence number: " << ending_residue_sequence_number_
         << ", Start insertion code: " << starting_residue_insertion_code_
         << ", End insertion code: " << ending_residue_insertion_code_
         << ", Selected n termination: " << GetStringFormatOfSelectedNTermination()
         << ", Selected c termination: " << GetStringFormatOfSelectedCTermination()         
         << endl;
}







