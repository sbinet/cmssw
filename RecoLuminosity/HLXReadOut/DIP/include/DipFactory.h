#ifndef DIPFACTORY_H_INCLUDED
#define DIPFACTORY_H_INCLUDED

class DipSubscription;
class DipPublication;
class DipSubscriptionListener;
class DipPublicationErrorHandler;
class DipBrowser;

#include "DipException.h"
#include "DipData.h"
#include "StdTypes.h"


/**
* Class used to create publications and/or subscribers.
*/
class DipDllExp DipFactory {
private:
//	DipFactory(const DipFactory& other);			// Disallow copying
//	DipFactory& operator=(const DipFactory& other);		// ...and assignment

public:
	virtual ~DipFactory() { }

	
	/**
	* Create a subscription with the specified topic name. Note the type of the subscription is not
	* known untill the publication transmits the first data
	* @param topicname name of the publication. Cloned
	* @param listener handler for connection/disconnection/error and data events. Ownership remains with caller.
	* @return The publication object that data is sent through. Owned by caller.
	*/
	virtual DipSubscription* createDipSubscription(const char* topicname, DipSubscriptionListener* listener) throw ( DipException ) = 0;

	/**
	* Create a publication with the specified topic name. Note the type of the publication is not
	* defined untill the publication of the first data.
	* @param topicname name of the publication, cloned
	* @param errHandler handler to be used by the returned publication object. Ownership remains with caller.
	* @return The publication object that data is sent through. Owned by caller.
	*/
	virtual DipPublication* createDipPublication(const char* topicname, DipPublicationErrorHandler* errHandler) throw ( DipException ) = 0;


	virtual void destroyDipSubscription(DipSubscription* subscription) throw ( DipException ) = 0;
	virtual void destroyDipPublication(DipPublication* publication) throw ( DipException ) = 0;


	// This method needed to be able to create different types of DipData
	// depending on what suits the transporting best.
	virtual DipData* createDipData() = 0;


	/**
	* create  a browser to browse the DIP namespace. Caller owns the returned
	* browser.
	*/
	virtual DipBrowser* createDipBrowser() = 0;

protected:
	DipFactory() { }
};

#endif //DIPFACTORY_H_INCLUDED

