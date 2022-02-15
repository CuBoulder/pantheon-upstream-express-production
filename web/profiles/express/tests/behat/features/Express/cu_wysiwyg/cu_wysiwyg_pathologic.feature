@wysiwyg @core
Feature: WYSIWYG Pathologic tests

# Pathologic replaces the specified URL(s) with whatever the BaseURL is.
# Since that changes with each install, we'll test that the specified URL is no longer there
# TO Do: insert real baseURL.

@javascript
Scenario: Pathologic should change URLs
  Given I am logged in as a user with the "developer" role
  And I am on "admin/config/content/formats/wysiwyg"
  And I fill in "filters[pathologic][settings][local_paths]" with "http://www.colorado.edu/p1eb825ce549"
  And I press "Save"
  And I go to "node/add/page"
  And I fill in "edit-title" with "PathologicTest"
  And I follow "Disable rich-text"
  And I fill in "Body" with "<a href=\"http://www.colorado.edu/p1eb825ce549/testpage\" name=\"myPathoName\" id=\"myPathoName\" >Change This Link</a>"
  When I press "Save"
  # TO DO: check that baseURL has replaced Pathologic pattern
  # Then the "#myPathoName" element should have "{baseURL}/testpage" in the "href" attribute
  Then the response should not contain "http://www.colorado.edu/p1eb825ce549/testpage"
