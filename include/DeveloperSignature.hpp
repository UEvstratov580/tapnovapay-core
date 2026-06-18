#ifndef DEVELOPER_SIGNATURE_HPP
#define DEVELOPER_SIGNATURE_HPP

#include <string>
#include <vector>

namespace TapNovaPay {

class DeveloperSignature {
public:
    // Перевірка підпису розробника
    static bool verifyDeveloperSignature(const std::string& data);
    
    // Генерація підпису для релізу
    static std::string generateSignature(const std::string& data);
    
    // Перевірка цілісності EXE
    static bool verifyExeIntegrity();
    
private:
    static std::string m_developer_public_key;
    static std::string m_signature;
};

} // namespace TapNovaPay

#endif
