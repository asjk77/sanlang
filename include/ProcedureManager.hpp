#ifndef SANLANG_PROCEDUREMANAGER_HPP
#define SANLANG_PROCEDUREMANAGER_HPP

typedef std::string ProcedureKey;
typedef std::function<void()>CallableProcedure;

class ProcedureManager
{
public:
    ProcedureManager() {}
    ~ProcedureManager() {}

    static std::unique_ptr< ProcedureManager > sInstance;
    static void StaticInit() { sInstance.reset( new ProcedureManager() ); }
private:
    typedef std::unordered_map< ProcedureKey,
            CallableProcedure > ProcedureKeyToProcedureMap;

    ProcedureKeyToProcedureMap mProcuedures; 
};


#endif /* SANLANG_PROCEDUREMANAGER_HPP */
