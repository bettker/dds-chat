#include "IDL_IMPL/ChatDDS_DCPS.hpp"

#include <iostream>
#include <string>
#include <vector>

class ChatListener : public virtual dds::sub::DataReaderListener<ChatDDS::Message>, public virtual dds::sub::NoOpDataReaderListener<ChatDDS::Message>,
    public virtual dds::sub::DataReaderListener<ChatDDS::SystemMessage>, public virtual dds::sub::NoOpDataReaderListener<ChatDDS::SystemMessage> {
private:
    std::vector<std::string>* messages = nullptr;
    std::string querySys;

public:
    ChatListener(std::string _username, std::vector<std::string>* _messages);

    virtual void on_data_available(dds::sub::DataReader<ChatDDS::Message>& reader);

    virtual void on_data_available(dds::sub::DataReader<ChatDDS::SystemMessage>& reader);
};
