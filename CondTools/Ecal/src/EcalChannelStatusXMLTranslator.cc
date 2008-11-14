#include <iostream>
#include <sstream>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax/SAXException.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>


#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"
#include "CondTools/Ecal/interface/EcalChannelStatusXMLTranslator.h"

#include "CondTools/Ecal/interface/DOMHelperFunctions.h"
#include "CondTools/Ecal/interface/XMLTags.h"

using namespace XERCES_CPP_NAMESPACE;
using namespace xuti;
using namespace std;





int  EcalChannelStatusXMLTranslator::readXML(const std::string& filename, 
					     EcalCondHeader& header,
					     EcalChannelStatus& record){



  XMLPlatformUtils::Initialize();

  XercesDOMParser* parser = new XercesDOMParser;
  parser->setValidationScheme( XercesDOMParser::Val_Never );
  parser->setDoNamespaces( false );
  parser->setDoSchema( false );
  
  parser->parse(filename.c_str());

  DOMDocument* xmlDoc = parser->getDocument();
  if (!xmlDoc) {
    cout << "EcalChannelStatusXMLTranslator::Error parsing document" << endl;
    return -1;
  }

  DOMElement* elementRoot = xmlDoc->getDocumentElement();

  xuti::readHeader(elementRoot,header);

  DOMNode * cellnode = getChildNode(elementRoot,Cell_tag);

  while(cellnode)
    {
      uint16_t csc = 0;

      DetId detid = readCellId(cellnode);

      DOMNode* c_node = getChildNode(cellnode,ChannelStatusCode_tag);
      GetNodeData(c_node,csc);

      EcalChannelStatusCode ecalCSC = EcalChannelStatusCode(csc);
      record[detid] = ecalCSC;

      cellnode = cellnode->getNextSibling();

      while(cellnode && cellnode->getNodeType() != DOMNode::ELEMENT_NODE)
	cellnode = cellnode->getNextSibling();

 
    }  

  delete parser;
  XMLPlatformUtils::Terminate();
  return 0;
  
  
}
  




  int EcalChannelStatusXMLTranslator::writeXML(const std::string& filename, 
					       const EcalCondHeader& header,
					       const EcalChannelStatus& record){
  
  


    XMLPlatformUtils::Initialize();

    DOMImplementation*  impl =
      DOMImplementationRegistry::getDOMImplementation(fromNative("LS").c_str());

    DOMWriter* writer =static_cast<DOMImplementationLS*>(impl)->createDOMWriter( );
    writer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true);

    DOMDocumentType* doctype = impl->createDocumentType( fromNative("XML").c_str(), 0, 0 );
    DOMDocument *    doc = 
         impl->createDocument( 0, fromNative(ChannelStatus_tag).c_str(), doctype );


    doc->setEncoding(fromNative("UTF-8").c_str() );
    doc->setStandalone(true);
    doc->setVersion(fromNative("1.0").c_str() );

    
    DOMElement* root = doc->getDocumentElement();
 
    xuti::writeHeader(root,header);

    for(int cellid = EBDetId::MIN_HASH;
	cellid < EBDetId::SIZE_HASH;
	++cellid)
      {

	uint32_t rawid = EBDetId::unhashIndex(cellid);

	if(!record[rawid].getStatusCode()) continue;
      
	DOMElement* cellnode = doc->createElement(fromNative(Cell_tag).c_str());
	root->appendChild(cellnode);

	writeCellId(cellnode,rawid);	  

	WriteNodeWithValue(cellnode,ChannelStatusCode_tag,record[rawid].getStatusCode());

	  	  	  
      }



   
    for(int cellid = EEDetId::MIN_HASH;
	cellid < EEDetId::SIZE_HASH;
	++cellid)
      {
	  
	if(!EEDetId::validHashIndex(cellid)) continue;
	  
	uint32_t rawid = EEDetId::unhashIndex(cellid); 

	if(!record[rawid].getStatusCode()) continue;

	DOMElement* cellnode = doc->createElement( fromNative(Cell_tag).c_str());
	root->appendChild(cellnode);

	writeCellId(cellnode,rawid);
	WriteNodeWithValue(cellnode,ChannelStatusCode_tag,record[rawid].getStatusCode());
	  
      }
    

    LocalFileFormatTarget file(filename.c_str());
 
    writer->writeNode(&file, *root);
 
    doc->release();
    //   XMLPlatformUtils::Terminate();

    return 0;
  }


