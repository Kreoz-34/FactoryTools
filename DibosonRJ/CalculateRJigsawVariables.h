#ifndef DibosonRJ_CalculateRJigsawVariables_H
#define DibosonRJ_CalculateRJigsawVariables_H

#include <EventLoop/Algorithm.h>

class RJigsawCalculator;

class CalculateRJigsawVariables : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;

  enum RJigsawCalculatorName {
    none = 0,
    lvlv = 1
  };

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!

  RJigsawCalculatorName  m_calculator_name;

  RJigsawCalculator     * m_calculator;//!

  // this is a standard constructor
  CalculateRJigsawVariables ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // this is needed to distribute the algorithm to the workers
  ClassDef(CalculateRJigsawVariables, 1);
};

#endif
