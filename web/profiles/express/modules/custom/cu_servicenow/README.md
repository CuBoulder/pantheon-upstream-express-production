# Using CU ServiceNow

## Configuring your ServiceNow Key
This module is meant to use a single service account username and password.
This must be set in the site's settings.php file under the conf variable:

`$conf['sn_key'] = 'password';`

Without this key, your module will not be able to make any calls to the 
ServiceNow (SN) URL.

If known username and password aren't working, contact OIT for a new password.

## Configure ServiceNow environment to use.
The configuration page for cu_servicenow, go to 
"admin/config/content/servicenow".

On that page there will be two options: environment and status.

There are two options for the environment:

 - Sandbox
 - Production
 
The "Sandbox" option can be used for testing. The "Production" option will send
form submissions directly to the live environment and create actual incidents.
Choose the option that best suites your needs.

## Turning on the ServiceNow integration per form
Each form must have the SN integration enabled to be used. It is disabled by 
default.

To enable this option on your form:

 - Go to your form's edit page (Ex. https://mywebsite.com/node/1/edit)
 - Go to "Publishing options" in the bottom left corner of the page
 - Below "Published" and "Sticky at top of lists", select "Enable ServiceNow 
 Integration"
 - Save webform
 
Now your webform will make a call to the configured SN environment.

## Configure the form's "Assignment Map"
Our ServiceNow incident submissions require a number of fields. 

 - Caller (person submitting the incident)
 - Assignment Group (what group the incident is coming from)
 - Business Service (the nature of issue is dependent on business)
 - Nature of Issue (second part of assignment piece)
 - Contact Email (email address of submitter)
 - Short Description (think email title of incident)
 - Description (this is where the bulk of the information is kept)
 
The "Caller" and "Contact Email" fields are populated automatically from your
Drupal account. "Assignment Group" has been prepopulated to use "Office of 
Strategic Relations" as this is coming from a Web Express site. 

"Short description" and "Description" must be created as fields inside your
form.

### Setting the Business Service and Nature of Issue for the form
A list of all available options for these fields has already been loaded upon
form creation. It is located on the "form settings" tab under, "Edit webform".

Look for the field labeled, "ServiceNow Incident Assignment".

The select list options are populated directly from the SN environment for your
site.

Select the incident assignment that's correct for your form and click "save 
configuration". This will fulfill both the "Business Service" and "Nature of 
Issue" fields that are required.

### Creating the "Short description" and "Description" fields
This is the same as creating a field for a field with an additional select 
option during the field creation process.

For example, if I create a textfield form field, in the "edit component" stage
of the field creation process--and if SN integration is enabled--I'll see a 
select list with the following options under the label, "Map this field to a 
ServiceNow Incident field below:"

 - -No Selection- (effectively leaving it blank)
 - Short Description
 - Description
 
As you'd expect, selecting one of them will then send the values of that field
to SN as the "Short description" or "Description" field.

A complete form should have both "Short description" and 
"Description" setup like this to meet the incident submission requirements.

## Testing a form submission
Once the form has been created and published, a simple test to see if the form
is sending incidents to SN correctly is to simply fill in and submit the form.

If the submission is successful, a message with the following text will be 
shown on the "form submitted" page.

`Your incident number is INC0000001, please keep this number for your records.`

If there was a problem sending the incident request to SN, you will see the 
following message instead:

`There was a problem sending your request to ServiceNow. Please contact the 
site owner.`

### Submitting a form while SN integration is disabled
If you submit a form when either the form specific integration is disabled 
(under "Edit form" in "Publishing options"), or the global SN integration is
disabled (located at "admin/config/content/servicenow"), you will see not see
either message from the previous section.

Instead, you will see a usual Drupal form submit take place. So if incidents
are not being created from form submissions, it's likely that one of the 
methods of disabling the SN integration have been selected.

## Troubleshooting
Logs are kept of both successful and unsuccessful SN requests inside the 
watchdog table. 

For an error, look for the following:

`ServiceNow api not communicating correctly: `

It will be followed by the request information.

For a successful SN submission, look for the following:

`ServiceNow incident was successfully sent: INC0000001`

Primary location of documentation for SN API: https://docs.servicenow.com/bundle/geneva-servicenow-platform/page/integrate/inbound_rest/concept/c_RESTAPI.html
