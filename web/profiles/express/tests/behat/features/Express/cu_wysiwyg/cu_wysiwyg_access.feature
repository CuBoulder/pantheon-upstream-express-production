@wysiwyg @core
Feature: WYSIWYG Access Feature
When I login to the website
As a content editor, site owner, administrator or developer
I should be able to access the functionality of the WYSIWYG editor

@wysiwyg
Scenario Outline: An authenticated user should have WYSIWYG selected as the the default text format
  Given  I am logged in as a user with the <role> role
  When I am on "node/add/page"
  Then the "select[name='body[und][0][format]'] option[selected='selected']" element should contain "WYSIWYG"

  Examples:
  | role           |
  | site_editor    |
  | site_owner     |
  | administrator  |
  | developer      |

@javascript
Scenario: The WYSIWYG editor contains all the shortcodes
  Given I am logged in as a user with the 'site_owner' role
  When I go to "node/add/page"
  And I wait for the "#cke_1_top" element to appear
  Then I should see a ".cke_button__button_sc_generator_button" element
  And I should see a ".cke_button__caption_sc_generator_button" element
  And I should see a ".cke_button__icon_sc_generator_button" element
  And I should see a ".cke_button__give_sc_generator_button" element
  And I should see a ".cke_button__expand_sc_generator_button" element
  And I should see a ".cke_button__map_sc_generator_button" element
  And I should see a ".cke_button__box_sc_generator_button" element
  And I should see a ".cke_button__video_sc_generator_button" element
  And I should see a ".cke_button__soundcloud_embed_button" element
  And I should see a ".cke_button__link_icon" element
