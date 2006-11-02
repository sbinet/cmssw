#ifndef _DQMServices_WebComponents_WebInterface_h_
#define _DQMServices_WebComponents_WebInterface_h_

#include "xgi/Method.h"
#include "xdata/UnsignedLong.h"
#include "cgicc/HTMLClasses.h"

#include "xdaq/include/xdaq/Application.h"
#include "xgi/include/xgi/Utils.h"
#include "xgi/include/xgi/Method.h"

#include "DQMServices/UI/interface/MonitorUIRoot.h"

#include "DQMServices/WebComponents/interface/WebPage.h"
#include "DQMServices/WebComponents/interface/MessageDispatcher.h"
#include "DQMServices/WebComponents/interface/ME_map.h"


class WebInterface
{

 private:

  std::string exeURL;
  std::string appURL;
  std::multimap<std::string, std::string> conf_map;

  MessageDispatcher msg_dispatcher;

 protected:

  MonitorUserInterface ** mui_p;
  WebPage * page_p;

 public:

  WebInterface(std::string _exeURL, 
	       std::string _appURL, 
	       MonitorUserInterface ** _mui_p)
    {
      exeURL = _exeURL;
      appURL = _appURL;
      mui_p = _mui_p;
      

      std::cout << "created a WebInterface for the DQMClient, the url = " << appURL << std::endl;
      std::cout << "within context = " << exeURL << std::endl;
    }

  virtual ~WebInterface() 
    {
    }

  std::string getContextURL()     { return exeURL; }
  std::string getApplicationURL() { return appURL; }

  void handleRequest        (xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);
  void handleStandardRequest(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);

  virtual void handleCustomRequest(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception)
    {
    };

  /// Answers requests by sending the webpage of the application
  virtual void Default(xgi::Input * in, xgi::Output * out ) throw (xgi::exception::Exception);

  /// Answers connection configuration requests
  void Configure(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
  
  /// Answer navigator requests 
  void Open(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
  void Subscribe(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
  void Unsubscribe(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);

  /// Outputs the subdirectories and files of "directory". Called by any of the above three.
  void printNavigatorXML(std::string directory, xgi::Output * out);
  
  /// Answers ContentViewer requests
  void ContentsOpen(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
  void printContentViewerXML(std::string current, xgi::Output * out);

  /// Answers Messages requests
  void printMessagesXML(xgi::Output *out);

  /// Answers viewer requests
  void DrawGif(xgi::Input * in, xgi::Output * out) throw (xgi::exception::Exception);
  void printMap(ME_map view_map, std::string id);

  /// Adds widgets to the page
  void add(std::string, WebElement *);

  /// Adds messages to the message dispatcher
  void sendMessage(std::string the_title, std::string the_text, MessageType the_type);

  std::string get_from_multimap(std::multimap<std::string, std::string> &mymap, std::string key);

};

#endif
