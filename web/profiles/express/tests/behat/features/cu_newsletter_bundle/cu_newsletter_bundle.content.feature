@NewsletterBundle
Feature: Newsletter Content Type
When I login to a Web Express website
As an authenticated user
I should be able to create, edit, and delete Newsletters

# 1) CREATE NEWSLETTER TAXONOMY
# 2) A VERY SIMPLE NEWSLETTER CAN BE CREATED
# 3) CREATE SUPPORTING ARTICLES FOR NEWSLETTER
# 4) FLESH OUT NEWSLETTER WITH MORE CONTENT

# 1) CREATE NEWSLETTER TAXONOMY
Scenario: Bundle functionality - Create the Newsletter Taxonomy
Given I am logged in as a user with the "site_owner" role
And I am on "admin/structure/taxonomy/newsletter/add"
And I fill in "Name" with "Digital Arts Magazine"
And I fill in "Newsletter Path" with "digitalarts"
And I press "Save"
Then I should see "Created new term Digital Arts Magazine"

# 2) A VERY SIMPLE NEWSLETTER CAN BE CREATED
Scenario: Node Functionality - A very simple Newsletter node can be created
Given I am logged in as a user with the "site_owner" role
And I go to "node/add/newsletter"
And I fill in "edit-field-newsletter-title-und-0-value" with "Sample Newsletter"
And I select "Digital Arts Magazine" from "edit-field-newsletter-type-und"
And I fill in "Body" with "This is the introductory section of the newsletter."
When I press "edit-submit"
Then I should see "Newsletter Digital Arts Magazine - Sample Newsletter has been created."
And I press "edit-publish"
Then I should be on "/newsletter/digitalarts/sample-newsletter"
And I should see "Digital Arts Magazine - Sample Newsletter and all attached articles are now published"

# 3) CREATE SUPPORTING ARTICLES FOR NEWSLETTER
Scenario: Create two articles for use in Newsletter
Given I am logged in as a user with the "site_owner" role
And I go to "node/add/article"
And I fill in "Title" with "Newsletter Article One"
And I press "Save"
Then I should see "Article Newsletter Article One has been created"
Then I go to "node/add/article"
And I fill in "Title" with "Newsletter Article Two"
And I press "Save"
Then I should see "Article Newsletter Article Two has been created"

# 4) FLESH OUT NEWSLETTER WITH MORE CONTENT
Scenario: Node functionality - Flesh out newsletter with more content
Given I am logged in as a user with the "site_owner" role
And I am on "newsletter/digitalarts/sample-newsletter"
And I follow "Edit"
And I fill in "edit-field-newsletter-section-und-0-field-newsletter-section-title-und-0-value" with "Read About Digital Arts"
And I fill in "edit-field-newsletter-section-und-0-field-newsletter-section-content-und-0-field-newsletter-articles-und-0-target-id" with "Newsletter Article One"
And I press "Add another item"
And I fill in "edit-field-newsletter-section-und-0-field-newsletter-section-content-und-1-field-newsletter-articles-und-0-target-id" with "Newsletter Article Two"
And I fill in "edit-field-newsletter-text-block-und-0-field-newsletter-block-title-und-0-value" with "A Text Block of Information"
And I press "edit-submit"
And I press "edit-publish"
Then I should see "Digital Arts Magazine - Sample Newsletter and all attached articles are now published"
And I should see "Read About Digital Arts"
And I should see "Newsletter Article One"
And I should see "Newsletter Article Two"
And I should see "A Text Block of Information"
