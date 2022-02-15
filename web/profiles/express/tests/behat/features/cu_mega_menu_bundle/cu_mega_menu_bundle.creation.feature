@cu_mega_menu_bundle
Feature: Mega Menu
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create and render a mega menu

Scenario: An authenticated user should be able to create a mega menu
    Given  I am logged in as a user with the "site_owner" role
    When I go to "admin/structure/mega-menu/add"
    Then I should see "Add a Mega Menu"
    And I fill in "edit-title" with "About Mega Menu"
    And I fill in "edit-field-mega-menu-label-und-0-value" with "About Us"
    And I fill in "Text Above" with "This is text above the mega menu."
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_links_label][und][0][value]" with "Mega Menu Label One"
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_link_fc][und][0][field_mega_menu_link][und][0][title]" with "Mega Menu Link One"
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_link_fc][und][0][field_mega_menu_link][und][0][url]" with "https://www.colorado.edu"
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_link_fc][und][0][field_mega_menu_link_desc][und][0][value]" with "Link One Description"
    # Add another link
    And I press "field_mega_menu_links_und_0_field_mega_menu_link_fc_add_more"
    # And I wait for AJAX
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_link_fc][und][1][field_mega_menu_link][und][0][title]" with "Mega Menu Link Two"
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_link_fc][und][1][field_mega_menu_link][und][0][url]" with "https://www.colorado.edu"
    And I fill in "field_mega_menu_links[und][0][field_mega_menu_link_fc][und][1][field_mega_menu_link_desc][und][0][value]" with "Link Two Description"
    # Add another section
    And I press "field_mega_menu_links_add_more"
    # And I wait for AJAX
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_links_label][und][0][value]" with "Mega Menu Label Two"
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_link_fc][und][0][field_mega_menu_link][und][0][title]" with "Mega Menu Link Three"
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_link_fc][und][0][field_mega_menu_link][und][0][url]" with "https://www.colorado.edu"
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_link_fc][und][0][field_mega_menu_link_desc][und][0][value]" with "Link Three Description"
    # Add another link
    And I press "field_mega_menu_links_und_1_field_mega_menu_link_fc_add_more"
    # And I wait for AJAX
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_link_fc][und][1][field_mega_menu_link][und][0][title]" with "Mega Menu Link Four"
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_link_fc][und][1][field_mega_menu_link][und][0][url]" with "https://www.colorado.edu"
    And I fill in "field_mega_menu_links[und][1][field_mega_menu_link_fc][und][1][field_mega_menu_link_desc][und][0][value]" with "Link Four Description"

    And I fill in "Text Below" with "This is text below the mega menu."

    And I press "Save"
    Then I should see "About Mega Menu"

    Then I am on "admin/structure/menu/manage/main-menu"
    And I should see "Main Menu"
    And I follow "configure item"
    And I check "Enable mega menu on this menu item"
    And I select "About Mega Menu" from "edit-mega-menu-reference"
    And I press "Save"

    Then I am on "/"
    Then I should see "About Us"
    Then I should see "Mega Menu Label One"
    Then I should see "Mega Menu Label Two"
    Then I should see "Mega Menu Link One"
    Then I should see "Mega Menu Link Two"
    Then I should see "Mega Menu Link Three"
    Then I should see "Mega Menu Link Four"
    Then I should see "Link One Description"
    Then I should see "Link Two Description"
    Then I should see "Link Three Description"
    Then I should see "Link Four Description"
